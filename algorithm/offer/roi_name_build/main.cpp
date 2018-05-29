#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string angle_view[3] = { "8", "6", "4" };
	string pos[4] = { "UL", "UR", "DR", "DL" };
	string h_v[2] = { "H", "V" };
    string f[3] = {"_1_8", "_1_4", "_1_2"};

    vector<string> sfr_roi_names;
	string roi_name = "";
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 4; j++){
			for (int k = 0; k < 2; k++){
				roi_name = "SFR" + h_v[k] + "_" + pos[j] + angle_view[i];
				sfr_roi_names.push_back(roi_name);
			}
		}
	}
	sfr_roi_names.push_back("SFRH_Center");
	sfr_roi_names.push_back("SFRV_Center");

    for(int i = 0; i < sfr_roi_names.size(); i++){
        cout << sfr_roi_names[i]<< endl;
    }


    return 0;
}
