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
//#include "interpolation_nts3.h"
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

/**************************************************************************************/
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

bool sortByAxisX(Scalar i, Scalar j)
{
	return	i[0] < j[0];
}

void generateROI(vector<Rect>& rois, int image_width, int image_height){
	rois.resize(8, Rect(0, 0, 0, 0));
	//8个roi，纵向中间2个，mark点外侧左右两边各3个
	int roi_w = image_width / 25;
	int roi_w_2 = roi_w >> 1;
	
	//中间2个roi的位置
	int image_width_1_2 = image_width >> 1;
	rois[0] = Rect((image_width_1_2 - roi_w_2), (int)((image_height * 0.25) - roi_w_2), roi_w, roi_w);
	rois[1] = Rect((image_width_1_2 - roi_w_2), (int)((image_height * 0.75) - roi_w_2), roi_w, roi_w);

	//左侧3个roi的位置
	int image_width_1_8 = image_width >> 3;
	rois[2] = Rect((image_width_1_8 - roi_w_2), (int)((image_height * (1 / 6.0)) - roi_w_2), roi_w, roi_w);
	rois[3] = Rect((image_width_1_8 - roi_w_2), (int)((image_height >> 1) - roi_w_2), roi_w, roi_w);
	rois[4] = Rect((image_width_1_8 - roi_w_2), (int)((image_height * (5 / 6.0)) - roi_w_2), roi_w, roi_w);

	//右侧3个roi的位置
	int image_width_7_8 = image_width - image_width_1_8;
	rois[5] = Rect((image_width_7_8 - roi_w_2), (int)((image_height * (1 / 6.0)) - roi_w_2), roi_w, roi_w);
	rois[6] = Rect((image_width_7_8 - roi_w_2), (int)((image_height >> 1) - roi_w_2), roi_w, roi_w);
	rois[7] = Rect((image_width_7_8 - roi_w_2), (int)((image_height * (5 / 6.0)) - roi_w_2), roi_w, roi_w);
}

string calc_roi_pos(vector<Rect>& rois, const Mat& image, int image_width, int image_height){
 	string ret_d = "";

	double min_val, max_val;
	minMaxLoc(image, &min_val, &max_val);
	para_map["m_threshold_0"] = min_val + (max_val - min_val) / 3;
	para_map["m_max_area"] = image_width*image_height / (min_mul);

	camCV::location::findMarkAndBlocks m_detectAlgo;

	bool m_ret_detect;
	vector<cv::Scalar> m_detected_marks;
	vector<vector<cv::Point>> m_detected_blocks;

	m_detectAlgo.setShowResult(false);

	m_detectAlgo.setDetectItem(true, false);
	m_detectAlgo.setMarkCircleError(para_map["m_circle_error"]);

	m_detectAlgo.setBinaryType(camCV::location::findMarkAndBlocks::type_normal);

	m_detectAlgo.setDownScale((int)para_map["m_down_scale"]);
	m_detectAlgo.setThreshold(para_map["m_threshold_0"], para_map["m_threshold_1"], image_width, image_height);

	m_detectAlgo.setArea(para_map["m_min_area"], para_map["m_max_area"], 0.0, 0.0);

	m_ret_detect = m_detectAlgo.detect(m_detected_marks, m_detected_blocks, image);

#if calc_mean
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
			
			double m1 = m_v1 / m_v;
			double m2 = m_v / m_v1;
			ret_d += (boost::format(",%g,%g,%g,%g") % m_v % m_v1 % m1 % m2).str();
		}
		
	}
#endif

	if (m_ret_detect) {
		int32_t start_x = 0;

		for (int32_t i = 0; i < (int)m_detected_marks.size(); i++) {
			if (i > start_x) {
				if (fabs(m_detected_marks[i][1] - m_detected_marks[i - 1][1]) > (para_map["m_y_line_diff"] * image_height)) {
					std::sort(&m_detected_marks[start_x], &m_detected_marks[i], sortByAxisX);
					start_x = i;
				}

				if (i == m_detected_marks.size() - 1) {
					std::sort(m_detected_marks.begin() + start_x, m_detected_marks.end(), sortByAxisX);
				}
			}
		}
		camCV::location::autoROI_4Marks auto_roi(image_width, image_height, para_map["m_ideal_mark"], para_map["m_y_line_diff"]);

		auto ret_auto_roi = auto_roi.calcAutoROIInfo(m_detected_marks, m_detected_blocks);

		double m_Rotation = auto_roi.getRotation();
		double m_Shift_x = abs(auto_roi.getRealCenterX() - image_width / 2);
		double m_Shift_y = abs(auto_roi.getRealCenterY() - image_height / 2);
		double m_efl = 35, m_pixel_size = 1;
		double m_Tilt_x = 0.0, m_Tilt_y = 0.0;
		if (m_efl != -1 && m_pixel_size != -1){
			m_Tilt_x = atan(m_pixel_size*m_Shift_x / m_efl);
			m_Tilt_y = atan(m_pixel_size*m_Shift_y / m_efl);
		}

		if (ret_auto_roi == camCV::location::error_none) {
			int32_t align_pixels = 2;

			for (size_t n = 0; n < rois.size(); n++) {
				Rect & r = rois[n];
				Point pt_tl = auto_roi.calcROIPos(Point(r.x, r.y));

				pt_tl.x = pt_tl.x / align_pixels * align_pixels;//?????
				pt_tl.y = pt_tl.y / align_pixels * align_pixels;

				r.x = pt_tl.x;
				r.y = pt_tl.y;
			}
		}
	}

	return ret_d;
}

Mat getMatRect(const Mat& mat, Rect rPos)
{
	Mat rMAT;
	Rect rRect;

	rRect.x = 0;
	rRect.y = 0;
	rRect.width = mat.cols + 1;
	rRect.height = mat.rows + 1;

	if ((rRect.contains(rPos.tl()) == true) &&
		(rRect.contains(rPos.br()) == true)) {
		rMAT = mat.colRange(rPos.tl().x, rPos.br().x)
			.rowRange(rPos.tl().y, rPos.br().y);
	}

	return rMAT;
}

/************************************************************************************/
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
	para_map["m_ideal_mark"] = 0.35;
	para_map["m_y_line_diff"] = 0.15;
	para_map["m_circle_error"] = 0.075;
	para_map["m_down_scale"] = 2;
	para_map["m_threshold_0"] = 100;
	para_map["m_threshold_1"] = 0.3;
	para_map["m_min_area"] = 10;
	para_map["m_max_area"] = 1000;
	para_map["mark_point_nums"] = 4;
}

void rotate_image(const Mat& src, Mat& dst ,double angle){
	dst = Mat::zeros(src.rows, src.cols, src.type());

	Point center = Point(src.cols / 2, src.rows / 2);

	Mat rot_mat(2, 3, CV_32FC1);
	rot_mat = getRotationMatrix2D(center, angle, 1);

	warpAffine(src, dst, rot_mat, dst.size());

#if show
	char * source_window = "source_window";
	namedWindow(source_window, CV_WINDOW_AUTOSIZE);
	Mat show_src;
	resize(src, show_src, Size(src.cols / 12, src.rows / 12));
	imshow(source_window, show_src);

	char * warp_window = "warp_window";
	namedWindow(warp_window, CV_WINDOW_AUTOSIZE);
	Mat show_rotate_dst;
	resize(rotate_dst, show_rotate_dst, Size(src.cols / 12, src.rows / 12));
	imshow(warp_window, show_rotate_dst);

	waitKey(0);
#endif
}
/*************************************************************************************/
int MTFHistogram(double &mtf, int color_channel, Mat& mROI, double percent, int OB = 0, int X = 0) {
	int ret = 0;

	Mat roi_grey;

	if (mROI.channels() == 3) {
		switch (color_channel) {
		case 0:
		case 1:
		case 2: {
			vector<Mat> channels;
			split(mROI, channels);

			if (channels.size() == 3) {
				roi_grey = channels[color_channel];
			}
		}
				break;
		default:
			cvtColor(mROI, roi_grey, CV_BGR2GRAY);
			break;
		}
	}
	else {
		roi_grey = mROI;
	}

	int hist_size[] = { 256 };
	float range[] = { 0, 256 };
	const float* ranges[] = { range };
	int channels_grey[] = { 0 };

	Mat	hist;

	calcHist(&roi_grey, 1, channels_grey, Mat(),
		hist, 1, hist_size, ranges,
		true,
		false);

	bool	isNormalize = false;
	double	dTotalPixels = 0.0;

	if (isNormalize) {
		normalize(hist, hist, 0, 1, NORM_MINMAX, -1, Mat());
		dTotalPixels = fabs(percent);
	}
	else {
		dTotalPixels = fabs(percent) * roi_grey.cols * roi_grey.rows;
	}

	double	dAvgL = 0;
	double	dPixelsL = 0;
	double	dSumL = 0;

	for (int i = 0; i < hist_size[0]; i++) {
		if (dPixelsL + hist.at<float>(i) >= dTotalPixels) {
			dSumL += i * (dTotalPixels - dPixelsL);
			dPixelsL = dTotalPixels;

			break;
		}
		else {
			dPixelsL += hist.at<float>(i);
			dSumL += hist.at<float>(i) * i;
		}
	}

	if (fabs(percent) > 0.0000001) {
		dAvgL = dSumL / dPixelsL;
	}
	else {
		dAvgL = 1.0;
	}

	double	dAvgH = 0;
	double	dPixelsH = 0;
	double	dSumH = 0;

	for (int i = hist_size[0] - 1; i >= 0; i--) {
		if (dPixelsH + hist.at<float>(i) >= dTotalPixels) {
			dSumH += i * (dTotalPixels - dPixelsH);
			dPixelsH = dTotalPixels;

			break;
		}
		else
		{
			dPixelsH += hist.at<float>(i);
			dSumH += hist.at<float>(i) * i;
		}
	}

	if (fabs(percent) > 0.0000001) {
		dAvgH = dSumH / dPixelsH;
	}
	else {
		dAvgH = 0.0;
	}

	mtf = (dAvgH - dAvgL) / (dAvgH + dAvgL - 2 * OB - X)* 100.0;

	return	ret;
}

void calc_mtf(const Mat& image, vector<Rect>& rois, vector<double>& vec_mtf){
	for (auto n = 0; n < rois.size(); n++){
		double mtf = -1.0;
		Mat ROI = getMatRect(image, rois[n]);
		MTFHistogram(mtf, 3, ROI, 0.15);
		vec_mtf.push_back(mtf);
	}
}
/************************************************************************************/
string data_str(double angle, const vector<Rect>& rois, const vector<double>& vec_mtf){
	string ret_str = (boost::format("%.1f,%d,") % angle % rois[0].width).str();

	for (auto i = 0; i < rois.size(); i++){
		ret_str += (boost::format("%d,%d,") % rois[i].x % rois[0].y).str();
	}
	for (auto i = 0; i < rois.size(); i++){
		ret_str += (boost::format("%g,") % vec_mtf[i]).str();
	}
	ret_str += "\n";
	
	return ret_str;
}

void report(string path, const string& data){
	ofstream data_file;
	data_file.open("D:/NTS3Image/auto_roi_failed_images/pic/tilt_MTF/param_data.csv", ofstream::app | ofstream::out);
	if (data_file.is_open()){
		path += "\n";
		data_file << path;
		
		string table_head = "angle,roi_w";
		for (int i = 0; i < 8; i++){
			table_head += (boost::format(",MTF%d_x") % i).str();
			table_head += (boost::format(",MTF%d_y") % i).str();
		}
		for (int i = 0; i < 8; i++){
			table_head += (boost::format(",MTF%d_v") % i).str();
		}
		table_head += "\n";
		
		data_file << table_head;
		data_file << data;

		data_file.close();
	}
}

Rect drawString(Mat& img, string text, Point coord, Scalar color, float fontScale, int thickness, int fontFace)
{
	//获取文本大小和基线
	int baseline = 0;
	Size textSize = getTextSize(text, fontFace, fontScale, thickness, &baseline);
	baseline += thickness;
	// 为左/右或上/下调整校正坐标
	if (coord.y >= 0) {
		//图像左上角的文本的左上角的坐标，因此按行向下移动
		coord.y += textSize.height;
	}
	else {
		//图像左下角的文本的左下角的坐标，因此从底部上来
		coord.y += img.rows - baseline + 1;
	}
	// 如果希望变成右侧调整
	if (coord.x < 0) {
		coord.x += img.cols - textSize.width + 1;
	}

	if ((coord.x + textSize.width + 10) > img.cols) {
		coord.x = img.cols - 10 - textSize.width;
	}

	// 获取文本的边界矩形
	Rect boundingRect = Rect(coord.x, coord.y - textSize.height, textSize.width, baseline + textSize.height);

	// 画出平滑的文本
	putText(img, text, coord, fontFace, fontScale, color, thickness, CV_AA);

	//让用户知道文本的多大，以防他们想安排些事情
	return boundingRect;
}

void drawOsd(Mat& display, const vector<Rect>& rois, const vector<double>& vec_mtf)
{
	int fontFace = CV_FONT_HERSHEY_SIMPLEX;
	//根据0402, 20M的像素大小, 按比例设置字体大小
	double fontScale = (double)display.cols * 2 / 5120 + 1;
	int thickness = 5 * display.cols / 5120 + 1;

	for (size_t n = 0; n < rois.size(); n++) {
		Rect rect = rois[n];
		int texty = rect.y;

		string text = (boost::format("MTF%d: %.2f") % n % vec_mtf[n]).str();
		Rect r_value = drawString(display, text, Point(rect.x + rect.width + 6, texty), CV_RGB(0, 0, 255), fontScale, thickness, fontFace);
		texty += r_value.height + 10;

		rectangle(display, rect, CV_RGB(0, 0, 255), 5);
	}

	Mat show_rotate_dst;
	resize(display, show_rotate_dst, Size(display.cols / 8, display.rows / 8));

	static int save_cnt = 0;
	//"D:/NTS3Image/auto_roi_failed_images/pic/tilt_MTF/show/"
	string path = (boost::format("D:/NTS3Image/auto_roi_failed_images/pic/tilt_MTF/show/MTF%d.bmp") % save_cnt++).str();
	imwrite(path, show_rotate_dst);
#if show
	char * warp_window = "roi_pos_value";
	namedWindow(warp_window, CV_WINDOW_AUTOSIZE);
	
	imshow(warp_window, show_rotate_dst);

	waitKey(0);
	destroyAllWindows();
#endif
}

/************************************************************************************/
int main(void){
	init_param();
	
	string p = "D:/NTS3Image/auto_roi_failed_images/pic/tilt_MTF/color/";
	vector<string> img_names = { "cle1.bmp", "cle2.bmp", "blur.bmp" };

	for (auto i = 0; i < img_names.size(); i++){
		string img_path = p + img_names[i];

		Mat src = imread(img_path, 1);

		int image_width = src.cols;
		int image_height = src.rows;

		vector<Rect> rois;
		generateROI(rois, image_width, image_height);

		Mat rotate_img = src.clone();

		double step_angle = 2.0, start_angle = -18, total_angle = 36;//360;

		string data = "";
		for (double angle = start_angle; angle < (start_angle + total_angle); angle += step_angle){
			rotate_image(src, rotate_img, angle);

			vector<Rect> cur_rois = rois;
			calc_roi_pos(cur_rois, rotate_img, image_width, image_height);

			vector<double> mtfs;
			calc_mtf(rotate_img, cur_rois, mtfs);

			data += data_str(angle, cur_rois, mtfs);

			drawOsd(rotate_img, cur_rois, mtfs);
		}

		report(img_path, data);
	}
	

	return 0;
}
