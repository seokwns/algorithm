#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void push(queue<pair<int, int>>& table, vector<bool>& visited, pair<int, int> where) {
    if (where.first < 0 || where.first > 100000) {
        return;
    }
    if (!visited[where.first]) {
        table.push(where);
        visited[where.first] = true;
    }
}

int main(void) {
    queue<pair<int, int>> table;
    vector<bool> visited (100001, false);
    int from, to;
    cin >> from >> to;

    table.push({from, 0});
    pair<int, int> current;

    while(!table.empty()) {
        current = table.front();
        if (current.first == to) break;
        table.pop();
        push(table, visited, {current.first - 1, current.second + 1});
        push(table, visited, {current.first + 1, current.second + 1});
        push(table, visited, {current.first * 2, current.second + 1});
    }

    cout << current.second << "\n";
    return 0;
}