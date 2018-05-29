#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;

void printV(vector<int> v, bool is_ok = false)
{
    if(is_ok){
    for(size_t i = 0; i < v.size(); i++)
    {
        printf("%3d ", i);
        //cout << i << "  ";
    }
    cout << endl;
    }
    for(size_t i = 0; i < v.size(); i++)
    {
        printf("%3d ", v[i]);
        //cout << v[i] << " ";
    }
    cout << endl;
}


class Solution {
public:
    vector< int > is_conn;

    int swimInWater(vector<vector<int> >& grid) {
        size_t n = grid.size();

        int lo = max(grid[0][0], grid[n-1][n-1]), hi = n*n-1, ha = lo;

        is_conn.resize(n*n-1, -1);

        while(lo < hi){
            ha = lo + (hi-lo)/2;
            bool is_ha  = is_connected(grid, ha, n);
            //printV(is_conn, true);
            if(is_ha){
                bool is_ha_1 = is_connected(grid, ha-1, n);
                if(!is_ha_1){
                    hi = ha;
                    break;
                }
                else{
                    hi = ha-1;
                }
            }
            else{
                lo = ha+1;
            }
        }

        return hi;
    }

    bool is_connected(vector<vector<int> >& grid, int ti, int n){

        if(is_conn[ti] != -1){
            return is_conn[ti];
        }
        const int dx[4] = {-1, 0, 1, 0};
        const int dy[4] = {0, 1, 0, -1};

        bool is_c = false;

        vector<bool> seen(n*n-1, 0);

        vector<int> cur(2);
        queue<vector<int> > q;
        int cur_v = grid[cur[0]][cur[1]];
        if(cur_v <= ti){
            seen[cur_v] = true;
            q.push(cur);
        }

        while(!q.empty()){
            cur = q.front();
            q.pop();

            if(cur[0] == n-1 && cur[1] == n-1){
                is_c = true;
                break;
            }
            //printf("v=%3d ", grid[cur[0]][cur[1]]);printV(cur);

            for(int i = 0; i < 4; i++){
                int nx = cur[0] + dx[i];
                int ny = cur[1] + dy[i];
                if(0 > nx || nx > n-1 || 0 > ny || ny > n-1){
                    continue;
                }
                cur_v = grid[nx][ny];
                if(!seen[cur_v] && cur_v <= ti){

                    //cout << grid[cur[0]][cur[1]]<<" push " << grid[nx][ny] << endl;
                    vector<int> next(2);
                    next[0] = nx;
                    next[1] = ny;
                    q.push(next);
                    seen[cur_v] = true;

                }
            }

        }

        is_conn[ti] = is_c;

        return is_c;
    }
};


int main()
{
    int a[20][20] = {{105,209,171,91,64,394,279,11,45,84,207,321,216,197,381,377,78,19,203,198},{141,10,335,170,265,104,338,40,397,376,346,356,212,154,280,177,247,90,87,360},{99,59,242,149,344,172,276,230,133,193,284,345,46,363,30,142,295,70,224,200},{251,88,379,72,319,272,243,165,180,182,387,264,23,67,137,342,125,139,144,367},{94,211,151,37,290,112,343,157,300,271,260,373,369,294,289,57,44,12,20,340},{220,368,186,277,181,187,273,214,315,337,328,18,231,223,331,75,275,96,135,150},{202,74,27,184,399,341,49,62,261,86,314,383,302,257,61,148,268,120,36,25},{15,253,285,185,226,146,126,122,83,361,110,234,183,239,52,190,152,81,136,188},{39,199,358,26,301,116,32,386,29,138,393,159,102,140,370,227,282,111,5,33},{189,35,132,54,210,235,28,353,281,127,318,58,100,286,384,24,307,252,80,103},{244,176,124,79,161,355,218,398,392,380,225,121,178,352,329,322,167,51,313,85},{107,118,351,287,324,283,48,320,82,364,357,16,219,330,89,143,241,262,71,191},{95,97,3,7,270,249,213,339,362,298,4,258,248,390,299,306,156,164,109,229},{221,9,228,160,274,263,374,147,98,63,13,41,326,396,349,372,385,317,325,266},{53,131,173,312,174,114,250,119,163,22,246,92,278,365,292,215,14,304,204,73},{233,323,366,130,378,305,311,93,134,217,297,327,232,194,240,1,208,6,310,47},{69,101,332,195,254,236,50,166,56,168,267,17,359,347,65,316,238,296,348,222},{76,123,129,293,391,2,245,108,303,38,66,55,43,256,162,60,179,77,336,21},{196,388,333,395,42,382,291,237,288,375,128,145,192,158,350,259,206,34,334,255},{201,175,153,68,205,155,115,269,389,169,371,308,117,31,354,8,113,309,106,0}};
    vector< vector<int> > grid;
    for(int i = 0; i < 20; i++){
        vector<int> tmp(&(a[i][0]), &(a[i][0])+20);
        grid.push_back(tmp);
        printV(grid[i]);
    }

/*
    vector< vector<int> > grid(2, vector<int>(2, 0));
    grid[0][0] = 3;
    grid[0][1] = 2;
    grid[1][0] = 0;
    grid[1][1] = 1;

    vector< vector<int> > grid(2, vector<int>(2, 0));
    grid[0][0] = 0;
    grid[0][1] = 2;
    grid[1][0] = 1;
    grid[1][1] = 3;

    int a[5][5] = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
    vector< vector<int> > grid;
    for(int i = 0; i < 5; i++){
        vector<int> tmp(&(a[i][0]), &(a[i][0])+5);
        grid.push_back(tmp);
        printV(grid[i]);
    }

        int a[5][5] = {{7,23,21,9,5},{3,20,8,18,15},{14,13,1,0,22},{2,10,24,17,12},{6,16,19,4,11}};
    vector< vector<int> > grid;
    for(int i = 0; i < 5; i++){
        vector<int> tmp(&(a[i][0]), &(a[i][0])+5);
        grid.push_back(tmp);
        //printV(grid[i]);
    }
        int a[4][4] = {{11,15,3,2},{6,4,0,13},{5,8,9,10},{1,14,12,7}};
    vector< vector<int> > grid;
    for(int i = 0; i < 4; i++){
        vector<int> tmp(&(a[i][0]), &(a[i][0])+4);
        grid.push_back(tmp);
        printV(grid[i]);
    }
    int a[20][20] = {{105,209,171,91,64,394,279,11,45,84,207,321,216,197,381,377,78,19,203,198},{141,10,335,170,265,104,338,40,397,376,346,356,212,154,280,177,247,90,87,360},{99,59,242,149,344,172,276,230,133,193,284,345,46,363,30,142,295,70,224,200},{251,88,379,72,319,272,243,165,180,182,387,264,23,67,137,342,125,139,144,367},{94,211,151,37,290,112,343,157,300,271,260,373,369,294,289,57,44,12,20,340},{220,368,186,277,181,187,273,214,315,337,328,18,231,223,331,75,275,96,135,150},{202,74,27,184,399,341,49,62,261,86,314,383,302,257,61,148,268,120,36,25},{15,253,285,185,226,146,126,122,83,361,110,234,183,239,52,190,152,81,136,188},{39,199,358,26,301,116,32,386,29,138,393,159,102,140,370,227,282,111,5,33},{189,35,132,54,210,235,28,353,281,127,318,58,100,286,384,24,307,252,80,103},{244,176,124,79,161,355,218,398,392,380,225,121,178,352,329,322,167,51,313,85},{107,118,351,287,324,283,48,320,82,364,357,16,219,330,89,143,241,262,71,191},{95,97,3,7,270,249,213,339,362,298,4,258,248,390,299,306,156,164,109,229},{221,9,228,160,274,263,374,147,98,63,13,41,326,396,349,372,385,317,325,266},{53,131,173,312,174,114,250,119,163,22,246,92,278,365,292,215,14,304,204,73},{233,323,366,130,378,305,311,93,134,217,297,327,232,194,240,1,208,6,310,47},{69,101,332,195,254,236,50,166,56,168,267,17,359,347,65,316,238,296,348,222},{76,123,129,293,391,2,245,108,303,38,66,55,43,256,162,60,179,77,336,21},{196,388,333,395,42,382,291,237,288,375,128,145,192,158,350,259,206,34,334,255},{201,175,153,68,205,155,115,269,389,169,371,308,117,31,354,8,113,309,106,0}};
    vector< vector<int> > grid;
    for(int i = 0; i < 20; i++){
        vector<int> tmp(&(a[i][0]), &(a[i][0])+20);
        grid.push_back(tmp);
        //printV(grid[i]);
    }



    int a[10][10] = {{55,33,29,78,47,62,60,79,41,54},{34,16,93,64,38,46,91,8,40,65},{22,74,12,70,28,80,90,32,6,45},{23,49,85,52,11,56,83,5,36,95},{31,48,14,89,76,82,19,26,97,63},{0,75,9,77,2,51,94,7,71,99},{35,81,44,87,43,18,67,17,13,57},{92,53,37,39,20,88,15,68,24,66},{27,69,84,3,72,10,61,30,50,58},{73,96,98,25,4,21,86,1,59,42}};
    vector< vector<int> > grid;
    for(int i = 0; i < 10; i++){
        vector<int> tmp(&(a[i][0]), &(a[i][0])+10);
        grid.push_back(tmp);
        printV(grid[i]);
    }
        */
    Solution sl;

    cout << sl.swimInWater(grid) << endl;

    return 0;
}
/*{{105,209,171,91,64,394,279,11,45,84,207,321,216,197,381,377,78,19,203,198},{141,10,335,170,265,104,338,40,397,376,346,356,212,154,280,177,247,90,87,360},{99,59,242,149,344,172,276,230,133,193,284,345,46,363,30,142,295,70,224,200},{251,88,379,72,319,272,243,165,180,182,387,264,23,67,137,342,125,139,144,367},{94,211,151,37,290,112,343,157,300,271,260,373,369,294,289,57,44,12,20,340},{220,368,186,277,181,187,273,214,315,337,328,18,231,223,331,75,275,96,135,150},{202,74,27,184,399,341,49,62,261,86,314,383,302,257,61,148,268,120,36,25},{15,253,285,185,226,146,126,122,83,361,110,234,183,239,52,190,152,81,136,188},{39,199,358,26,301,116,32,386,29,138,393,159,102,140,370,227,282,111,5,33},{189,35,132,54,210,235,28,353,281,127,318,58,100,286,384,24,307,252,80,103},{244,176,124,79,161,355,218,398,392,380,225,121,178,352,329,322,167,51,313,85},{107,118,351,287,324,283,48,320,82,364,357,16,219,330,89,143,241,262,71,191},{95,97,3,7,270,249,213,339,362,298,4,258,248,390,299,306,156,164,109,229},{221,9,228,160,274,263,374,147,98,63,13,41,326,396,349,372,385,317,325,266},{53,131,173,312,174,114,250,119,163,22,246,92,278,365,292,215,14,304,204,73},{233,323,366,130,378,305,311,93,134,217,297,327,232,194,240,1,208,6,310,47},{69,101,332,195,254,236,50,166,56,168,267,17,359,347,65,316,238,296,348,222},{76,123,129,293,391,2,245,108,303,38,66,55,43,256,162,60,179,77,336,21},{196,388,333,395,42,382,291,237,288,375,128,145,192,158,350,259,206,34,334,255},{201,175,153,68,205,155,115,269,389,169,371,308,117,31,354,8,113,309,106,0}}
[[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
[[11,15,3,2],[6,4,0,13],[5,8,9,10],[1,14,12,7]]
[[7,23,21,9,5],[3,20,8,18,15],[14,13,1,0,22],[2,10,24,17,12],[6,16,19,4,11]]
[[105,209,171,91,64,394,279,11,45,84,207,321,216,197,381,377,78,19,203,198],[141,10,335,170,265,104,338,40,397,376,346,356,212,154,280,177,247,90,87,360],[99,59,242,149,344,172,276,230,133,193,284,345,46,363,30,142,295,70,224,200],[251,88,379,72,319,272,243,165,180,182,387,264,23,67,137,342,125,139,144,367],[94,211,151,37,290,112,343,157,300,271,260,373,369,294,289,57,44,12,20,340],[220,368,186,277,181,187,273,214,315,337,328,18,231,223,331,75,275,96,135,150],[202,74,27,184,399,341,49,62,261,86,314,383,302,257,61,148,268,120,36,25],[15,253,285,185,226,146,126,122,83,361,110,234,183,239,52,190,152,81,136,188],[39,199,358,26,301,116,32,386,29,138,393,159,102,140,370,227,282,111,5,33],[189,35,132,54,210,235,28,353,281,127,318,58,100,286,384,24,307,252,80,103],[244,176,124,79,161,355,218,398,392,380,225,121,178,352,329,322,167,51,313,85],[107,118,351,287,324,283,48,320,82,364,357,16,219,330,89,143,241,262,71,191],[95,97,3,7,270,249,213,339,362,298,4,258,248,390,299,306,156,164,109,229],[221,9,228,160,274,263,374,147,98,63,13,41,326,396,349,372,385,317,325,266],[53,131,173,312,174,114,250,119,163,22,246,92,278,365,292,215,14,304,204,73],[233,323,366,130,378,305,311,93,134,217,297,327,232,194,240,1,208,6,310,47],[69,101,332,195,254,236,50,166,56,168,267,17,359,347,65,316,238,296,348,222],[76,123,129,293,391,2,245,108,303,38,66,55,43,256,162,60,179,77,336,21],[196,388,333,395,42,382,291,237,288,375,128,145,192,158,350,259,206,34,334,255],[201,175,153,68,205,155,115,269,389,169,371,308,117,31,354,8,113,309,106,0]]
*/
