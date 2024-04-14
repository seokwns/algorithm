#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int MOD = 1000000007;
    int answer = 0;
    vector< vector<int> > table (n + 1, vector<int> (m + 1, 0));
    table[1][1] = 1;
    
    for (vector<int> iter: puddles) {
        int x = iter[0];
        int y = iter[1];
        table[y][x] = -1;
    }
    
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            if (x == 1 && y == 1) continue;
            if (table[y][x] == -1) continue;
            
            int up = table[y - 1][x];
            if (up < 0) up = 0;
            
            int left = table[y][x - 1];
            if (left < 0) left = 0;
            table[y][x] = (up + left) % MOD;
        }
    }
    
    return table[n][m] % MOD;
}
