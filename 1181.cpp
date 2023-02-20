/*
https://www.acmicpc.net/problem/1181
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main(void) {
    int n;
    cin >> n;

    vector<string> words;
    for (int i = 0; i < n; i++) {
        string input;
        getline(cin, input);
        words.push_back(input);
    }

    
    return 0;    
}