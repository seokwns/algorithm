/*
https://www.acmicpc.net/problem/23322
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(void) {
    int n, k;
    cin >> n >> k;
    
    vector<int> choco;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        choco.push_back(t);
    }

    int day = 0;
    int eaten = 0;

    for (int i = k; i < n; i++) {
        sort(choco.begin(), choco.end());
        int len = choco.size();
        if (choco[0] == choco[len - 1]) break;

        day++;


    }

    return 0;
}