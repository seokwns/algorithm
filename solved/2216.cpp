#include <iostream>
#include <string>
#include <vector>
using namespace std;


int max(int a, int b, int c) {
    return max(a, max(b, c));
}

int main(void) {
    int A, B, C;
    cin >> A >> B >> C;

    string sx, sy;
    cin >> sx;
    cin >> sy;

    int x_len = sx.length();
    int y_len = sy.length();

    vector<vector<int>> dp(x_len + 1, vector<int> (y_len + 1, 0));
    for (int x = 1; x <= x_len; x++) dp[x][0] = dp[x - 1][0] + B;
    for (int y = 1; y <= y_len; y++) dp[0][y] = dp[0][y - 1] + B;

    for (int x = 1; x <= x_len; x++) {
        for (int y = 1; y <= y_len; y++) {
            dp[x][y] = max(
                dp[x - 1][y - 1] + (sx[x - 1] == sy[y - 1]? A : C),
                dp[x][y - 1] + B,
                dp[x - 1][y] + B
            );
        }
    }

    cout << dp[x_len][y_len] << endl;

    return 0;
}