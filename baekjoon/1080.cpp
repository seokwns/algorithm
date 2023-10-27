/*
https://www.acmicpc.net/problem/1080
*/
#include <iostream>
#include <vector>
using namespace std;


int n, m;
int answer = 0;
vector<vector<int>> A, B;

void getMatrix(vector<vector<int>>& mat) {
    for (int x = 0; x < n; x++) {
        vector<int> temp;
        for (int y = 0; y < m; y++) {
            char input;
            cin >> input;
            temp.push_back(input - '0');
        }
        mat.push_back(temp);
    }
}

void flip(int x, int y) {
    if (x + 2 < n && y + 2 < m) {
        for (int dx = 0; dx < 3; dx++) {
            for (int dy = 0; dy < 3; dy++) {
                A[x + dx][y + dy] = A[x + dx][y + dy] ^ 1;
            }
        }
        answer++;
    }
}

bool equals() {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (A[x][y] != B[x][y]) return false;
        }
    }
    return true;
}

int main(void) {
    cin >> n >> m;
    getMatrix(A); getMatrix(B);

    for (int x = 0; x < n - 2; x++) {
        for (int y = 0; y < m - 2; y++) {
            if (A[x][y] != B[x][y]) flip(x, y);
        }
    }

    if (equals()) cout << answer << endl;
    else cout << -1 << endl;
    return 0;
}