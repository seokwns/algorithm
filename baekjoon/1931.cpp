#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct compare {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) return a.first > b.first;
        return a.second > b.second;
    }
};

int main(void) {
    int n;
    cin >> n;

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        pq.emplace(start, end);
    }

    int count = 0;
    int time = -1;
    while (!pq.empty()) {
        pair<int, int> cur = pq.top(); pq.pop();
        if (cur.first >= time) {
            time = cur.second;
            count ++;
        }
    }

    cout << count << endl;
    return 0;
}