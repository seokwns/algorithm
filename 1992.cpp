#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;


int n;
queue<char> compress;
vector<vector<int>> view;

void input() {
    cin >> n;
    for (int x = 0; x < n; x++) {
        vector<int> row;
        string tmp;
        cin >> tmp;

        int len = tmp.length();
        for (int i = 0; i < len; i++) {
            row.push_back(tmp[i] - '0');
        }
        view.push_back(row);
    }
}

void solve(int x, int y, int r) {
    bool check = true;
    int checker = view[x][y];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < r; j++) {
            if (view[x + i][y + j] != checker) {
                check = false;
                break;
            }
        }
    }

    if (!check) {
        cout << "(";
        solve(x, y, r/2);
        solve(x, y + r/2, r/2);
        solve(x + r/2, y, r/2);
        solve(x + r/2, y + r/2, r/2);
        cout << ")";
    }
    else {
        cout << checker;
    }
}

int main(void) {
    input();
    solve(0, 0, n);
    cout << endl;
    return 0;
}