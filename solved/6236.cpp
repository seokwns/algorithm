/*
https://www.acmicpc.net/problem/6236
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int n, m;
vector<int> budget;

bool check(int out) {
    int count = 1;
    int remains = out;
    for (int i = 0; i < n; i++) {
        if (budget[i] > out) return false;
        if (budget[i] > remains) {
            count++;
            remains = out;
        }
        remains -= budget[i];
    }
    return count <= m;
}

int main(void) {
    cin >> n >> m;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        budget.push_back(input);
        sum += input;
    }

    int left = 0;
    int right = sum;
    int count = right;
    while(left <= right) {
        int mid = (left + right) / 2;
        if (check(mid)) {
            right = mid - 1;
            if (count > mid) count = mid;
        }
        else left = mid + 1;
    }
    cout << count << endl;

    return 0;
}