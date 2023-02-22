/*
https://www.acmicpc.net/problem/2553
*/
#include <iostream>
#include <cmath>
using namespace std;


int main(void) {
    int n;
    cin >> n;

    long long result = 1;
    for(int i = 1; i <= n; i++) {
        result = result * i;
        result = result % 1000000;
        while ( (result % 10) == 0 ) {
            result = result / 10;
        }
    }

    cout << (result % 10) << endl;

    return 0;
}