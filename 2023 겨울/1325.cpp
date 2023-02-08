#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


#define MAX 100000
vector<int> nodes[MAX];

void dfs(vector<bool>& visited, int i, int& cnt) {
    cnt++;
    visited[i] = true;
    for (auto iter : nodes[i]) {
        if (!visited[iter]) {
            dfs(visited, iter, cnt);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int from;
        int to;
        cin >> to >> from;
        nodes[from].push_back(to);
    }

    vector<int> answers;
    int max_count = 0;
    for (int i = 1; i <= n ; i++) {
        vector<bool> visited(n + 1, false);
        int cnt = 0;
        dfs(visited, i, cnt);

        if (max_count < cnt) {
            answers.clear();
            answers.push_back(i);
            max_count = cnt;
        }
        else if (cnt == max_count) {
            answers.push_back(i);
        }
    }

    for (auto answer : answers) {
        cout << answer << " ";
    }
    cout << "\n";

    return 0;
}
