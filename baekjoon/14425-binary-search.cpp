/*
https://www.acmicpc.net/problem/14425
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<string> s;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        s.push_back(input);
    }

    sort(s.begin(), s.end());

    int answer = 0;
    for (int i = 0; i < m; i++) {
        string input;
        cin >> input;
        if (binary_search(s.begin(), s.end(), input)) answer++;
    }

    cout << answer << "\n";
    return 0;
}