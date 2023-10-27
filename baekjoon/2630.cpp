#include <iostream>
#include <vector>
using namespace std;


void input(int& n, vector<vector<int>>& arr) {
    cin >> n;
    int input_;
    for (int x = 0; x < n; x++) {
        vector<int> temp;
        for (int y = 0; y < n; y++) {
            cin >> input_;
            temp.push_back(input_);
        }
        arr.push_back(temp);
    }
}

void division(int n, vector<vector<int>>& arr, int x, int y, int r, int& white, int& blue) {
    bool checking = true;
    int checker = arr[x][y];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < r; j++) {
            if (arr[x + i][y + j] != checker) {
                checking = false;
                break;
            }
        }
        if (!checking) break;
    }

    if (!checking) {
        division(n, arr, x, y, r/2, white, blue);
        division(n, arr, x, y + r/2, r/2, white, blue);
        division(n, arr, x + r/2, y, r/2, white, blue);
        division(n, arr, x + r/2, y + r/2, r/2, white, blue);
    }
    else {
        if (arr[x][y] == 0) white++;
        else blue++;
    }
}

void output(int white, int blue) {
    cout << white << "\n" << blue << endl;
}

int main(void) {
    int n, white = 0, blue = 0;
    vector<vector<int>> stage;
    input(n, stage);
    division(n, stage, 0, 0, n, white, blue);
    output(white, blue);
    return 0;
}