#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;


struct Node {
    int data;
    int changed;
    int f;
};

void getPrimes(vector<int>& primes) {
    for (int i = 2; i < 10000; i++) {
        if (primes[i] == 1) continue;
        else {
            for (int j = i + i; j < 10000; j += i) {
                primes[j] = 1;
            }
        }
    }
}

int str2int(string str) {
    int result = 0;
    for (int i = 0; i < str.length(); i++) {
        result = result * 10 + (str[i] - '0');
    }
    return result;
}

int solve(vector<int>& primes, int from, int to) {
    queue<pair<int, int> > bfs;
    vector<int> visited (10000, 0);
    bfs.push(make_pair(from, 0));
    visited[from] = 1;

    while (!bfs.empty()) {
        int current = bfs.front().first;
        int count = bfs.front().second;
        bfs.pop();

        if (current == to) {
            return count;
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j <= 9; j++) {
                string next = to_string(current);
                next[i] = '0' + j;
                int nextInt = str2int(next);
                if (visited[nextInt] == 1) continue;
                else if (nextInt >= 1000 && primes[nextInt] == 0) {
                    bfs.push(make_pair(nextInt, count + 1));
                    visited[nextInt] = 1;
                }
            }
        }
    }

    return -1;
}

int main(void) {
    vector<int> primes (10000, 0);
    primes[0] = 1;
    primes[1] = 1;
    getPrimes(primes);

    int n;
    cin >> n;

    vector<int> resultSet;
    while (n--) {
        int from, to;
        cin >> from >> to;

        int result = solve(primes, from, to);
        resultSet.push_back(result);
    }

    for (int i = 0; i < resultSet.size(); i++) {
        if (resultSet[i] != -1) cout << resultSet[i] << endl;
        else cout << "Impossible" << endl;
    }
    return 0;
}