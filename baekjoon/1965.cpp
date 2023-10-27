/*
최장 증가 부분 수열 문제 입니다.
O(n2) 의 시간 복잡도.

입력 배열을 순회하면서
자신보다 작고 dp 값이 +1 한 값보다 작으면 dp 1 증가

이거 왜 이러지
찾아봐야겠다
*/

#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    int n;
    cin >> n;

    vector<int> box(n);
    for (int i = 0; i < n; i++) {
        cin >> box[i];
    }

    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (box[j] < box[i] && dp[i] < dp[j] + 1) dp[i]++;
        }
    }

    int result = dp[0];
    for (auto count : dp) {
        if (result <= count) {
            result = count;
        }
    }

    cout << result << endl;
    return 0;
}