#include <iostream>
#include <string>
#include <stack>
using namespace std;


int count = 0;

void solve() {
    string input;
    cin >> input;

    int len = input.length();
    stack<int> stage;
    for (int i = 0; i < len; i++) {
        if (input[i] == '(') stage.push(1);
        else if (input[i] == ')') {
            stage.pop();
            if (input[i - 1] == '(') count += stage.size();
            else if (input[i - 1] == ')') count++;
        }
    }
}

int main(void) {
    solve();
    cout << count << endl;
    return 0;
}