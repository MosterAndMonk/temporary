#include <iostream>
#include <cstdio>
#include <io.h>
#include <stdint.h>
#include <fstream>
#include <map>
#include <cmath>

#include <boost/format.hpp>

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/operations.hpp>

using namespace cv;
using namespace std;

//#include "imageInfo.pb.h"
#include "camCV.h"
#include "camFile.h"
#include "autoROI.h"
#include "findMarksAndBlocks.h"

#ifdef _DEBUG
#pragma comment(lib, "nts3LoggingD.lib")
#pragma comment(lib, "NTSPropertyD.lib")
#pragma comment(lib, "videoDeviceInterfaceD.lib")
#pragma comment(lib, "PluginInterfaceD.lib")
#else
#pragma comment(lib, "nts3Logging.lib")
#pragma comment(lib, "NTSProperty.lib")
#pragma comment(lib, "videoDeviceInterface.lib")
#pragma comment(lib, "PluginInterface.lib")
#endif

#ifdef _DEBUG
#pragma comment(lib, "camCVD.lib")
#pragma comment(lib, "interpolation_nts3d.lib")
#else
#pragma comment(lib, "camCV.lib")
#pragma comment(lib, "interpolation_nts3.lib")
#endif

#ifdef	_DEBUG

#pragma comment(lib, "opencv_calib3d2413d.lib")
#pragma comment(lib, "opencv_contrib2413d.lib")
#pragma comment(lib, "opencv_core2413d.lib")
#pragma comment(lib, "opencv_features2d2413d.lib")
#pragma comment(lib, "opencv_flann2413d.lib")
#pragma comment(lib, "opencv_gpu2413d.lib")
#pragma comment(lib, "opencv_highgui2413d.lib")
#pragma comment(lib, "opencv_imgproc2413d.lib")
#pragma comment(lib, "opencv_legacy2413d.lib")
#pragma comment(lib, "opencv_ml2413d.lib")
#pragma comment(lib, "opencv_objdetect2413d.lib")
#pragma comment(lib, "opencv_ts2413d.lib")
#pragma comment(lib, "opencv_video2413d.lib")

#else

#pragma comment(lib, "opencv_calib3d2413.lib")
#pragma comment(lib, "opencv_contrib2413.lib")
#pragma comment(lib, "opencv_core2413.lib")
#pragma comment(lib, "opencv_features2d2413.lib")
#pragma comment(lib, "opencv_flann2413.lib")
#pragma comment(lib, "opencv_gpu2413.lib")
#pragma comment(lib, "opencv_highgui2413.lib")
#pragma comment(lib, "opencv_imgproc2413.lib")
#pragma comment(lib, "opencv_legacy2413.lib")
#pragma comment(lib, "opencv_ml2413.lib")
#pragma comment(lib, "opencv_objdetect2413.lib")
#pragma comment(lib, "opencv_ts2413.lib")
#pragma comment(lib, "opencv_video2413.lib")

#endif
const int max_buf = 300;
const int min_mul = 400;

map<string, double> para_map;
const string name[10] = { "0", "m_ideal_mark", "m_y_line_diff", "m_circle_error", "m_down_scale", "m_threshold_0", "m_threshold_1", "m_min_area", "m_max_area", "mark_point_nums" };

void detectCircle(){
Mat img = imread("D:/NTS3Image/auto_roi_failed_images/pic/1501674477387_0_20171108_144139.bmp", 0);
Mat cimg;
medianBlur(img, img, 5);
cvtColor(img, cimg, COLOR_GRAY2BGR);
//cvtColor(img, cimg, COLOR_GRAY2BGR);
//GaussianBlur(src_gray, src_gray, Size(9, 9), 2, 2);
vector<Vec3f> circles; //cv::HOUGH_GRADIENT
HoughCircles(img, circles, 3, 1, 10, 100, 30, 1, 30 
	// change the last two parameters
	// (min_radius & max_radius) to detect larger circles
	);
	
for( size_t i = 0; i < circles.size(); i++ )    {
	Vec3i c = circles[i];
	//LINE_AA, LINE_AA
	circle( cimg, Point(c[0], c[1]), c[2], Scalar(0,0,255), 3, 0);  
	circle( cimg, Point(c[0], c[1]), 2, Scalar(0,255,0), 3, 0);    
}
pyrDown( cimg, cimg, Size(cimg.cols/2, cimg.rows/4));
//imwrite("", img);
imshow("detected circles", cimg);
waitKey();
}

string calc_pos(Mat& image, int image_width, int image_height){
 	string ret_d = "";

	camCV::location::findMarkAndBlocks m_detectAlgo;

	bool m_ret_detect;
	vector<cv::Scalar> m_detected_marks;
	vector<vector<cv::Point>> m_detected_blocks;

	m_detectAlgo.setShowResult(true);

	m_detectAlgo.setDetectItem(true, false);
	m_detectAlgo.setMarkCircleError(para_map["m_circle_error"]);

	m_detectAlgo.setBinaryType(camCV::location::findMarkAndBlocks::type_normal);

	m_detectAlgo.setDownScale((int)para_map["m_down_scale"]);
	m_detectAlgo.setThreshold(para_map["m_threshold_0"], para_map["m_threshold_1"], image_width, image_height);

	m_detectAlgo.setArea(para_map["m_min_area"], para_map["m_max_area"], 0.0, 0.0);

	m_ret_detect = m_detectAlgo.detect(m_detected_marks, m_detected_blocks, image);
	
	const double M_PI = 3.1415926;

	if (m_detected_marks.size() >= para_map["mark_point_nums"]){
		if (image.channels() == 3){
			cvtColor(image, image, cv::COLOR_BGR2GRAY);
		}
		pair<double, double> mark_area(0.0, image_width*image_height);
		pair<double, double> not_mark_area(0.0, image_width*image_height);

		int mark_cnt = 0;
		int j = 0;
		for (int i = 0; i < m_detected_marks.size(); i++){
			Scalar & cur = m_detected_marks[i];
			double radius = sqrt(cur[2] / M_PI);
			
			Rect rec( (cur[0]-radius), (cur[1]-radius), radius*2, radius*2);
			Mat rec_roi(image, rec);

			Mat cir_mask(rec_roi.size(), rec_roi.type(), Scalar::all(0));
			circle(cir_mask, Point(radius, radius), radius, Scalar::all(255), -1);

			Mat crop = rec_roi & cir_mask;

			double m_v = mean(crop)[0]*4/ M_PI;
			
			double out_radius = radius * 2;
			Rect rec1((cur[0] - out_radius), (cur[1] - out_radius), out_radius * 2, out_radius * 2);
			Mat rec_roi1(image, rec1);

			Mat cir_mask1(rec_roi1.size(), rec_roi1.type(), Scalar::all(0));
			circle(cir_mask1, Point(out_radius, out_radius), out_radius, Scalar::all(255), -1);
			circle(cir_mask1, Point(out_radius, out_radius), out_radius*0.75, Scalar::all(0), -1);

			Mat crop1 = rec_roi1 & cir_mask1;

			double m_v1 = mean(crop1)[0] * 4 / (M_PI*(1 - 0.75*0.75));
			
// 			if (m_v < 40){
// 				mark_area.first = max(mark_area.first, cur[2]);
// 				mark_area.second = min(mark_area.second, cur[2]);
// 				mark_cnt++;
// 			}
// 			else{
// 				not_mark_area.first = max(not_mark_area.first, cur[2]);
// 				not_mark_area.second = min(not_mark_area.second, cur[2]);
// 			}
			double m1 = m_v1 / m_v;
			double m2 = m_v / m_v1;
			ret_d += (boost::format(",%g,%g,%g,%g") % m_v % m_v1 % m1 % m2).str();
		}

// 		if (mark_cnt == para_map["mark_point_nums"]){
// 			if (not_mark_area.first < mark_area.second){
// 				para_map["m_min_area"] = not_mark_area.first + (mark_area.second - not_mark_area.first) / 2;
// 			}
// 			else if (not_mark_area.second > mark_area.first){
// 				para_map["m_max_area"] = mark_area.first + (not_mark_area.second - mark_area.first) / 2;
// 			}
// 		}
// 		else if (mark_cnt > para_map["mark_point_nums"]){
// 
// 		}
		
	}

	return ret_d;
}

vector<string> getFile(string dir){
	string p =  dir + "*.bmp";

	vector<string> v;

	long hFile = 0;
	struct _finddata_t fileinfo;
	if ((hFile = _findfirst(p.c_str(), &fileinfo)) != -1){
		do{
			v.push_back((boost::format("%s%s") % dir.c_str() % fileinfo.name).str());
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
	return v;
}

void help_info(){
	for (int i = 1; i < 9; i++){
		cout << i << "." << name[i] << " = " << para_map[name[i]] << endl;
	}
	printf("if you want to modify param values, input the number, or else, 0\n");
	
	char cc = '1';
	cin >> cc;
	while ('1' <= cc && cc <= '8'){
		double v = 0.0;
		cin >> v;
		int c = cc - '0';
		para_map[name[c]] = v;
		cout << c << "." << name[c] << " = " << para_map[name[c]] << endl;
		
		cin >> cc;
	}
}

void init_param(){
	para_map["m_ideal_mark"] = 0.5;
	para_map["m_y_line_diff"] = 0.15;
	para_map["m_circle_error"] = 0.075;
	para_map["m_down_scale"] = 2;
	para_map["m_threshold_0"] = 100;
	para_map["m_threshold_1"] = 0.3;
	para_map["m_min_area"] = 10;
	para_map["m_max_area"] = 1000;
	para_map["mark_point_nums"] = 4;
}

int main(void){
	init_param();
	//string p = "D:/a_me/work/customers/guangda/20180331_mtf/input/20180403_4mark/";
	//string p = "D:/NTS3Image/auto_roi_failed_images/pic/dualaa/";
	//string p = "D:/NTS3Image/auto_roi_failed_images/pic/special/";
	//string p = "D:/NTS3Image/auto_roi_failed_images/pic/grid_sfr/";
	string p = "D:/NTS3Image/grid_sfr/";

	vector<string> file_names = getFile(p);
// 	if (file_names.size() == 0){
// 		file_names.push_back("frame_00_0_20180419T091708.bmp");
// 	}

	bool is_first_line = true;
	for (int i_f = 0; i_f < file_names.size(); i_f++){
		cout << "path: " << file_names[i_f] << endl;
		Mat image = imread(file_names[i_f], cv::IMREAD_GRAYSCALE);//, cv::IMREAD_GRAYSCALE
		//string info;
		//bool ret_read = camCV::camFile::readImage(NULL, file_names[i_f], info);
		//camCV::camFile::readImage(image.data, file_names[i_f], info);

		double min_val, max_val;
		minMaxLoc(image, &min_val, &max_val);
		para_map["m_threshold_0"] = min_val + (max_val-min_val)/3;

		int image_width = image.cols;
		int image_height = image.rows;

		para_map["m_max_area"] = image_width*image_height / (min_mul);
		string mark_val("");

		char c = 'n';
		while (c == 'n'){
			mark_val = calc_pos(image, image_width, image_height);
			cout << mark_val << endl;
			help_info();
			printf("Is mark point detected? y or n\n");
			cin >> c;
		}
		if (c == 'y'){
			ofstream data_file;
			data_file.open("D:/NTS3Image/auto_roi_failed_images/pic/param_data.csv", ofstream::app | ofstream::out);
			if (data_file.is_open()){
				string out = "";
				if (is_first_line){
					is_first_line = false;
					out += "file_name";
					for (int i = 1; i < 9; i++){
						out += ","+ name[i];
					}

					int j = 0;
					for (int i = 1; i <= 4; i++){
						out += (boost::format(",markpoint_%d_%d") % i % 1).str();
						out += (boost::format(",markpoint_%d_%d") % i % 2).str();
						out += (boost::format(",markpoint_%d_%d") % i % 3).str();
						out += (boost::format(",markpoint_%d_%d") % i % 4).str();
					}
					out += ",image_width,image_height";
					out += "\n";
				}

				out += file_names[i_f];

				for (int i = 1; i < 9; i++){
					out += (boost::format(",%g") % para_map[name[i]]).str();
				}

				out += mark_val;
				out += "\n";
				data_file << out;
				data_file.close();
			}
		}

	}
	
	return 0;
}
