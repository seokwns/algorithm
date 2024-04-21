#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int r = board.size();
    int c = board[0].size();
    int len = skill.size();
    
    vector<vector<int>> summary (r + 1, vector<int>(c + 1, 0));
    
    for (int i = 0; i < len; i++) {
        vector<int> cursor = skill[i];
        int type = pow(-1, cursor[0]);
        int r1 = cursor[1];
        int c1 = cursor[2];
        int r2 = cursor[3];
        int c2 = cursor[4];
        int degree = cursor[5] * type;
        
        summary[r1][c1] += +degree;
        summary[r1][c2+1] += -degree;
        summary[r2+1][c1] += -degree;
        summary[r2+1][c2+1] += +degree;
    }
    
    for (int x = 0; x <= r; x++) {
        for (int y = 1; y <= c; y++) {
            summary[x][y] += summary[x][y - 1];
        }
    }
    
    for (int y = 0; y < c; y++) {
        for (int x = 1; x < r; x++) {
            summary[x][y] += summary[x - 1][y];
        }
    }
    
    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            if (board[x][y] + summary[x][y] >= 1) {
                answer++;
            }
        }
    }
    return answer;
}
