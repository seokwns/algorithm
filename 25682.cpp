/*
https://www.acmicpc.net/problem/25682

왼쪽 상단을 기준으로 잡았을 때, (x,y) 인덱스 합이 짝수면 기준과 같은 색 / 홀수면 다른 색

*/
#include <iostream>
#include <vector>
using namespace std;


int calculation(char standard, int n, int m, int k, vector<vector<char>> stage) {
    vector<vector<int>> table (n + 1, vector<int> (m + 1, 0));

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            int value = 0;
            if ((x + y) % 2 == 0) value = (stage[x][y] != standard);
            else value = (stage[x][y] == standard);

            table[x + 1][y + 1] = table[x][y + 1] + table[x + 1][y] - table[x][y] + value;
        }
    }

    int count = n * m / 2;
    for (int x = 1; x < n + 2 - k; x++) {
        for (int y = 1; y < m + 2 - k; y++) {
            int ps = table[x + k - 1][y + k - 1] - table[x + k - 1][y - 1] - table[x - 1][y + k - 1] + table[x - 1][y - 1];
            count = min(count, ps);
        }
    }
    return count;
}

int main(void) {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<char>> stage;
    for (int x = 0; x < n; x++) {
        vector<char> temp;
        for (int y = 0; y < m; y++) {
            char input;
            cin >> input;
            temp.push_back(input);
        }
        stage.push_back(temp);
    }

    int answer = min(calculation('W', n, m, k, stage), calculation('B', n, m, k, stage));
    cout << answer << endl;
    return 0;
}