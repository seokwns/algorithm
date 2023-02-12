#include <iostream>
#include <cmath>

using namespace std;


int Z(int n, int r, int c) {
    long long counter = pow(2, n);
    long long quarter = pow(4, n) / 4;
    long long x = 0, y = 0;
    long long head = 0;
    while (n--) {
        if ((r - x) < counter / 2 && (c - y) < counter / 2) {
            head = head;
        }
        else if ((r - x) < counter / 2 && (c - y) >= counter / 2) {
            head = head + 1 * quarter;
            y += counter / 2;
        }
        else if ((r - x) >= counter / 2 && (c - y) < counter / 2) {
            head = head + 2 * quarter;
            x += counter / 2;
        }
        else if ((r - x) >= counter / 2 && (c - y) >= counter / 2) {
            head = head + 3 * quarter;
            x += counter / 2;
            y += counter / 2;
        }
        counter = counter / 2;
        quarter = quarter / 4;
    }
    return head;
}

int main(void) {
    int n, r, c;
    cin >> n >> r >> c;
    cout << Z(n, r, c) << endl;
    return 0;
}
