/*
https://www.acmicpc.net/problem/1326
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, from, to, result = -1;
    cin >> n;

    vector<int> stones;
    vector<bool> visited(n + 1, false);
    queue<pair<int, int>> stage;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        stones.push_back(input);
    }

    cin >> from >> to;

    stage.push({from, 0});
    visited[from] = true;

    while(!stage.empty()) {
        pair<int, int> iter = stage.front(); stage.pop();
        int current = iter.first;

        if (iter.first == to) {
            result = iter.second;
            break;
        }

        int alpha = stones[current - 1];
        for (int i = 1; current + alpha * i <= n; i++) {
            int next = current + alpha * i;
            if (!visited[next]) {
                stage.push({next, iter.second + 1});
                visited[next] = true;
            }
        }
        for (int i = 1; current - alpha * i >= 1; i++) {
            int next = current - alpha * i;
            if (!visited[next]) {
                stage.push({next, iter.second + 1});
                visited[next] = true;
            }
        }
    }

    cout << result << endl;
    return 0;
}