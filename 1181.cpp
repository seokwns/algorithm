/*
https://www.acmicpc.net/problem/1181
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


bool compare(string a, string b) {
    if (a.length() > b.length()) return false;
    else if (a.length() < b.length()) return true;
    return a < b;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> words;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        if (find(words.begin(), words.end(), input) == words.end()) 
            words.push_back(input);
    }

    sort(words.begin(), words.end(), compare);
    for (auto i : words) cout << i << "\n";
    return 0;    
}