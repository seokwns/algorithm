#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void input(vector<int>& a, int n) {
    int from, to;
    for (int i = 0; i < n; i++) {
        cin >> from >> to;
        a[from] = to;
    }
}

int solve(vector<int>& a) {
    vector<int> dp(501, 1);
    int max_length = 1;
    for (int i = 1; i <= 500; i++) {
        for (int j = 1; j < i; j++) {
            if (a[i] > a[j] && a[j] != 0 && a[i] != 0) dp[i] = max(dp[i], dp[j] + 1);
        }
        max_length = max(max_length, dp[i]);
    }
    return max_length;
}

int main(void) {
    int n;
    cin >> n;

    vector<int> lines (501, 0);
    input(lines, n);

    int counter = solve(lines);
    cout << (n - counter) << endl;

    return 0;
}