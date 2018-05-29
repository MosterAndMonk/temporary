#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int> >& points) {
        double max_area = 0.0;
        for(int i = 0; i < points.size(); i++){
            for(int j = 0; j < points.size(); i++){
                for(int k = 0; k < points.size(); k++){
                    if(i != j && j != k && i != k){
                        double area = points[i][0]*points[j][1] + points[j][0]*points[k][1] + points[k][0]*points[i][1];
                        area -= (points[i][0]*points[k][1] + points[j][0]*points[i][1] + points[k][0]*points[j][1]);
                        max_area = max(max_area, abs(area)/2);
                    }
                }
            }
        }
        return max_area;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
