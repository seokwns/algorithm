/*
https://www.acmicpc.net/problem/1654
*/
#include <iostream>
#include <vector>
using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int k, n;
    cin >> k >> n;

    vector<long long> lans;
    long long left = 1, right = 0;
    for (int i = 0; i < k; i++) {
        long long input;
        cin >> input;
        lans.push_back(input);

        if (right < input) right = input;
    }

    long long middle = right, answer = 0;
    while(left <= right) {
        middle = (left + right) / 2;

        int count = 0;
        for (int i = 0; i < k; i++) {
            count += lans[i] / middle;
        }

        if (count >= n) {
            left = middle + 1;
            //랜선의 최댓값을 업데이트 해야하므로 비교해서 더 큰 값을 저장
            if (answer < middle) answer = middle;
        }
        else right = middle - 1;
    }

    cout << answer << "\n";
    return 0;
}