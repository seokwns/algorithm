#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main(void) {
    int test_case;
    cin >> test_case;

    int dx[5] = {0, 0, 1, 0, -1};
    int dy[5] = {0, 1, 0, -1, 0};
    vector<int> worm_counts;

    for (int t_case = 0; t_case < test_case; t_case++) {
        int width;
        int height;
        int cab_counter;
        cin >> width >> height >> cab_counter;

        vector<vector<int>> stage(width, vector<int> (height, 0));
        for (int i = 0; i < cab_counter; i++) {
            int cab_x;
            int cab_y;
            cin >> cab_x >> cab_y;
            stage[cab_x][cab_y] = 1;
        }

        int counter = 0;
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        bool done = false;

        while(!done) {
            bool changed = false;
            while(!q.empty()) {
                pair<int, int> tmp = q.front();
                q.pop();

                for (int i = 0; i < 5; i++) {
                    int cx = tmp.first + dx[i];
                    int cy = tmp.second + dy[i];

                    if (cx >= 0 && cx < width && cy >= 0 && cy < height && stage[cx][cy] == 1) {
                        q.emplace(cx, cy);
                        stage[cx][cy] = 2;
                        changed = true;
                    }
                }
            }

            if (changed) counter ++;

            bool check = false;
            for (int i = 0; i < width; i++) {
                for (int j = 0; j < height; j++) {
                    if (stage[i][j] == 1) {
                        q.emplace(i, j);
                        check = true;
                        break;
                    }
                }
                if (check) break;
            }
            if (!check) done = true;
        }
        worm_counts.push_back(counter);
    }

    for (int i = 0; i < test_case; i++) {
        cout << worm_counts[i] << "\n";
    }

    return 0;
}