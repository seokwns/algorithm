#include <iostream>
#include <vector>
using namespace std;


int main(void) {
    int n;
    cin >> n;
    
    vector< vector<long long> > dp (n + 1, vector<long long> (10, 1));
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y < 10; y++) {
            dp[x][y] = (dp[x - 1][y] + dp[x][y - 1]) % 10007;
        }
    }

    cout << (dp[n][9])<< endl;
    return 0;
}