#include <iostream>
#include <string>

using namespace std;


int main(void) {
    string sentence;
    getline(cin, sentence);

    string uppers[9] = {"c", "j", "n", "m", "t", "s", "l", "d", "qu"};
    char vowels[6] = {'a', 'e', 'i', 'o', 'u', 'h'};
    int len = sentence.length();
    int counter = 1;
    int cursor = 0;

    for (int i = 0; i < len; i++) {
        if (sentence[i] == ' ' || sentence[i] == '-') {
            counter++;
            cursor = i + 1;
        }
        else if (sentence[i] == '\'') {
            bool is_vowel = false;
            for (int k = 0; k < 6; k++) {
                if (sentence[i + 1] == vowels[k]) is_vowel = true;
            }

            if (!is_vowel) continue;

            for (int j = 0; j < 9; j++) {
                int _len = uppers[j].length();
                string subs = sentence.substr(cursor, _len);
                if (i - cursor == _len && subs == uppers[j]) {
                    counter++;
                    cursor = i + 1;
                    break;
                }
            }
        }
    }
    cout << counter << endl;

    return 0;
}