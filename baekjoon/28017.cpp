#include <iostream>
#include <vector>
#include <limits>
using namespace std;


int main(void) {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > table (n, vector<int> (m, 0));
    vector<int> dp (m, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> table[i][j];
        }
    }

    for (int x = 0; x < n; x++) {
        vector<int> temp_dp = vector<int> (m, 0);
        for (int i = 0; i < m; i++) {
            int temp = numeric_limits<int>::max();
            for (int j = 0; j < m; j++) {
                if (i == j) continue;
                temp = min(temp, dp[j]);
            }
            temp_dp[i] = table[x][i] + temp;
        }
        dp = temp_dp;
    }

    int result = numeric_limits<int>::max();
    for (int i = 0; i < m; i++) {
        result = min(result, dp[i]);
    }

    cout << result << endl;

    return 0;
}