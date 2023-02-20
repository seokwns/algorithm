#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;


long long getLovelyNumber(long long n) {
    string num_str = to_string(n);
    int len = num_str.length();
    long long lovely_number = pow(10, len) - n - 1;
    return n * lovely_number;
}

long long getMaximumLovelyNumber(long long n) {
    string num_str = to_string(n);
    int len = num_str.length();
    long long c = pow(10, len);
    return getLovelyNumber(min(n, (long long)((c - 1) / 2)));
}

int main(void) {
    int test_cases;
    cin >> test_cases;

    vector<long long> results;
    for (int test = 0; test < test_cases; test++) {
        long long input;
        cin >> input;
        results.push_back(getMaximumLovelyNumber(input));
    }

    for (auto test : results) {
        cout << test << "\n";
    }

    return 0;
}