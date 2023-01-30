#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main(void) {
    int n;
    cin >> n;

    vector<string> word_list(n);
    vector<bool> check(n, true);

    for (int i = 0; i < n; i++) {
        cin >> word_list[i];
    }

    sort(word_list.begin(), word_list.end());

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (word_list[j].substr(0, word_list[i].size()) == word_list[i]) {
                check[i] = false;
                break;
            }
        }
    }

    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (check[i] == true) counter++;
    }
    cout << counter << endl;

    return 0;
}