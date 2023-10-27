#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int getDistance(vector< pair<int, int> > vec[1001], int from, int to) {
    int distance = 0;
    vector<int> visited (1001, 0);

    queue< pair<int, int> > bfs;
    bfs.push(make_pair(from, 0));

    while (!bfs.empty()) {
        pair<int, int> cursor = bfs.front();
        bfs.pop();

        for (int i = 0; i < vec[cursor.first].size(); i++) {
            int next = vec[cursor.first][i].first;
            int dist = vec[cursor.first][i].second;

            if (next == to) {
                return cursor.second + dist;
            }
            if (visited[next] == 0) {
                bfs.push(make_pair(next, cursor.second + dist));
                visited[next] = 1;
            }
        }
    }
}


int main(void) {
    ios::sync_with_stdio(0);
	cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector< pair<int, int> > vec[1001];

    int from, to, dist;
    for (int i = 0; i < n - 1; i++) {
        cin >> from >> to >> dist;
        vec[from].push_back(make_pair(to, dist));
        vec[to].push_back(make_pair(from, dist));
    }

    for (int i = 0; i < m; i++) {
        cin >> from >> to;
        int distance = getDistance(vec, from, to);
        cout << distance << endl;
    }

    return 0;
}