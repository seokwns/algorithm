#include <iostream>
#include <vector>
using namespace std;


int combination(int n, int r) {
    long long result = 1;
    for (int i = 0; i < r; i++) {
        result = result * (n - i);
    }
    for (int i = 1; i <= r; i++) {
        result /= i;
    }

    return result % 10007;
}

int main(void) {
    int n;
    cin >> n;

    cout << combination(9 + n, n) << endl;
    return 0;
}