#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void input(vector<vector<int>>& map, int n, int m, queue<pair<int, int>>& bfs, vector<pair<int, int>>& zeros) {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            cin >> map[x][y];
            if (map[x][y] == 0) zeros.push_back({x, y});
            if (map[x][y] == 2) bfs.push({x, y});
        }
    }
}

int search(vector<vector<int>> map, int n, int m, queue<pair<int, int>> bfs) {
    while (!bfs.empty()) {
        pair<int, int> current = bfs.front(); bfs.pop();
        for (int i = 0; i < 4; i++) {
            int next_x = current.first + dx[i];
            int next_y = current.second + dy[i];
            if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) continue;
            if (map[next_x][next_y] == 0) {
                map[next_x][next_y] = 2;
                bfs.push({next_x, next_y});
            }
        }
    }

    int counter = 0;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (map[x][y] == 0) {
                counter++;
            }
        }
    }

    return counter;
}

int main(void) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> map (n, vector<int> (m, 0));
    queue<pair<int, int>> bfs;
    vector<pair<int, int>> zeros;
    input(map, n, m, bfs, zeros);

    int zero_len = zeros.size();
    int max_safe = 0;
    for (int i = 0; i < zero_len; i++) {
        for (int j = i + 1; j < zero_len; j++) {
            for (int k = j + 1; k < zero_len; k++) {
                map[zeros[i].first][zeros[i].second] = 1;
                map[zeros[j].first][zeros[j].second] = 1;
                map[zeros[k].first][zeros[k].second] = 1;
                max_safe = max(max_safe, search(map, n, m, bfs));
                map[zeros[i].first][zeros[i].second] = 0;
                map[zeros[j].first][zeros[j].second] = 0;
                map[zeros[k].first][zeros[k].second] = 0;
            }
        }
    }
    cout << max_safe << endl;

    return 0;
}