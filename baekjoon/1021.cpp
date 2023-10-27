#include <iostream>
#include <deque>
#include <queue>

using namespace std;


int main(void) {
    int n, m;
    cin >> n >> m;

    queue<int> numbers;
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        numbers.push(tmp);
    }

    deque<int> table;
    for (int i = 1; i <= n; i++) {
        table.push_back(i);
    }

    int cnt = 0;
    while(m--) {
        int current = numbers.front();
        numbers.pop();
        int fr = table.front();
        if (current == fr) {
            table.pop_front();
        }
        else {
            int idx;
            for (int i = 0; i < table.size(); i++) {
                if (table.at(i) == current) {
                    idx = i;
                    break;
                }
            }
            if (idx > table.size() / 2) {
                while (current != table.front()) {
                    cnt++;
                    int tmp = table.back();
                    table.pop_back();
                    table.push_front(tmp);
                }
            }
            else {
                while (current != table.front()) {
                    cnt++;
                    int tmp = table.front();
                    table.pop_front();
                    table.push_back(tmp);
                }
            }
            table.pop_front();
        }
    }
    cout << cnt << "\n";

    return 0;
}