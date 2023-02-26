/*
https://www.acmicpc.net/problem/1935
*/
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;


int main(void) {
    int n;
    cin >> n;

    string expression;
    cin >> expression;

    vector<int> values;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        values.push_back(input);
    }

    int len = expression.length();
    stack<double> stage;
    string OPERATIONS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < len; i++) {
        char cursor = expression[i];
        if (OPERATIONS.find(cursor) != string::npos) {
            stage.push(values[cursor - 'A']);
        }
        else {
            double a = stage.top(); stage.pop();
            double b = stage.top(); stage.pop();
            if (cursor == '+') stage.push(b + a);
            else if (cursor == '-') stage.push(b - a);
            else if (cursor == '*') stage.push(b * a);
            else if (cursor == '/') stage.push(b / a);
        }
    }

    cout << fixed; cout.precision(2);
    cout << stage.top() << endl;

    return 0;
}