#include <string>
#include <vector>
#include <limits.h>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer (4, 0);
    
    int sx = INT_MAX;
    int sy = INT_MAX;
    int ex = 0;
    int ey = 0;
    
    for (int i = 0; i < wallpaper.size(); i++) {
        for (int j = 0; j < wallpaper[i].size(); j++) {
            if (wallpaper[i][j] == '#') {
                sx = min(sx, j);
                sy = min(sy, i);
                ex = max(ex, j);
                ey = max(ey, i);
            }
        }
    }
    
    answer[0] = sy;
    answer[1] = sx;
    answer[2] = ey + 1;
    answer[3] = ex + 1;
    return answer;
}