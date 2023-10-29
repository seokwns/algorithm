#include <iostream>
#include <vector>
using namespace std;

struct block {
    int tl;
    int tr;
    int bl;
    int br;
    block(int _tl, int _tr, int _bl, int _br): tl(_tl), tr(_tr), bl(_bl), br(_br) {};
};

int main(void) {
    int n;
    cin >> n;

    vector< vector<int> > table (n + 1, vector<int> (n + 1, 0));
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            cin >> table[x][y];
        }
    }

    vector< vector<block> > dp (n + 1, vector<block> (n + 1, {0, 0, 0, 0}));
    dp[1][2] = {1, 0, 0, 0};

    for (int y = 1; y <= n; y++) {
        for (int x = 3; x <= n; x++) {
            if (table[y][x] == 0) {
                int tl = dp[y - 1][x - 1].bl + dp[y - 1][x - 1].tr + dp[y - 1][x - 1].tl;
                int tr = dp[y - 1][x].tr + dp[y - 1][x].tl;
                int bl = dp[y][x - 1].bl + dp[y][x - 1].tl;

                if (table[y][x - 1] == 1) {
                    bl = 0;
                    tl = 0;
                }

                if (table[y - 1][x] == 1) {
                    tl = 0;
                    tr = 0;
                }
                
                dp[y][x] = {tl, tr, bl, 0};
            }
            else {
                dp[y][x] = {0, 0, 0, 0};
            }
        }
    }

    cout << dp[n][n].tl + dp[n][n].tr + dp[n][n].bl << endl;
    return 0;
}