/*
https://www.acmicpc.net/problem/1068
*/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;


vector<vector<int>> tree(51, vector<int> (0, 0));
int n, k;
int root = 0;
int leaf = 0;

int main(void) {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        if (input == -1) root = i;
        else tree[input].push_back(i);
    }

    cin >> k;

    deque<int> dq;
    dq.push_back(root);

    while(dq.size() != 0) {
        int iter = dq.front();
        dq.pop_front();

        int len = tree[iter].size();
        if (len == 0 && iter != k) leaf++;
        else if (len == 1 && tree[iter][0] == k) leaf++;
        else if (iter != k) {
            for (int i = 0; i < len; i++) {
                if (tree[iter][i] != k) dq.push_back(tree[iter][i]);
            }
        }
    }

    cout << leaf << endl;

    return 0;
}