#include <iostream>
#include <vector>
using namespace std;


void input(vector<int>& domino, int n) {
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        domino.push_back(tmp);
    }
}

int solve(vector<int>& domino, int n) {
    int counter = 1;

    for (int i = 0; i < n; i++) {
        long long sum = domino[i];
        int temp_counter = 1;
        for (int j = i + 1; j < n; j++) {
            if (sum >= domino[j]) {
                sum += domino[j];
                temp_counter++;
            }
        }
        counter = max(counter, temp_counter);
    }

    return counter;
}

int main(void) {
    int n;
    cin >> n;

    vector<int> domino;
    input(domino, n);

    cout << solve(domino, n) << endl;

    return 0;
}