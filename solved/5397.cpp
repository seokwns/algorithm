#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;


list<char> getPassword(string& input) {
    list<char> passwd;
    list<char>::iterator iter = passwd.end();
    int len = input.length();

    for (int i = 0; i < len; i++) {
        if (input[i] == '<') {
            if (iter == passwd.begin()) continue;
            iter--;
        }
        else if (input[i] == '>') {
            if (iter == passwd.end()) continue;
            iter++;
        }
        else if (input[i] == '-') {
            if (iter == passwd.begin()) continue;
            iter = passwd.erase(--iter);
        }
        else {
            passwd.insert(iter, input[i]);
        }
    }

    return passwd;
}

int main(void) {
    int n;
    cin >> n;

    vector<list<char>> passwords;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        passwords.push_back(getPassword(input));
    }

    for (auto password : passwords) {
        for (auto iter = password.begin(); iter != password.end(); iter++) {
            cout << *iter;
        }
        cout << "\n";
    }

    return 0;
}