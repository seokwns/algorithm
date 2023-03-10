#include <iostream>
#include <string>
#include <list>
using namespace std;


list<char> statement;
int m;

void input() {
    string input_statement;
    cin >> input_statement;
    int len = input_statement.length();

    for (int i = 0; i < len; i++) {
        statement.push_back(input_statement[i]);
    }
}

void edit() {
    cin >> m;
    list<char>::iterator iter = statement.end();
    for (int i = 0; i < m; i++) {
        char cmd;
        cin >> cmd;
        switch(cmd) {
            case 'L':
                if (iter == statement.begin()) continue;
                iter--;
                break;
            case 'D':
                if (iter == statement.end()) continue;
                iter++;
                break;
            case 'B':
                if (iter == statement.begin()) continue;
                iter = statement.erase(--iter);
                break;
            case 'P':
                char pushed_char;
                cin >> pushed_char;
                statement.insert(iter, pushed_char);
                break;
        }
    }
}

void output() {
    for (auto chr : statement) {
        cout << chr;
    }
    cout << endl;
}

int main(void) {
    input();
    edit();
    output();
    return 0;
}