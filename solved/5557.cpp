#include <iostream>
#include <vector>
using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;

    vector< vector<long long> > dp (n, vector<long long> (21, 0));
    int input;

    cin >> input;
    dp[0][input] = 1;

    for (int i = 1; i < n; i++) {
        cin >> input;
        for (int j = 0; j <= 20; j++) {
            if (dp[i - 1][j] == 0) continue;
            else {
                if (j + input <= 20 && j + input >= 0) {
                    dp[i][j + input] += dp[i - 1][j];
                }
                if (j - input <= 20 && j - input >= 0) {
                    dp[i][j - input] += dp[i - 1][j];
                }
            }
        }
    }

    cout << dp[n - 2][input] << endl;
    
    return 0;
}