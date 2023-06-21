#include <iostream>
#include <vector>
#include <limits>
using namespace std;


void input(vector<int>& buildings, int n) {
    for (int i = 0; i < n; i++) {
        cin >> buildings[i];
    }
}

double getGradient(int sx, int sy, int ex, int ey) {
    return (double(ey - sy) / double(ex - sx));
}

int solve(vector<int>& buildings, int n) {
    int max_count = 0;
    for (int i = 0; i < n; i++) {
        int temp = 0;
        double bg = numeric_limits<double>::max();
        for (int j = i - 1; j >= 0; j--) {
            double current_gradient = getGradient(i, buildings[i], j, buildings[j]);
            if (current_gradient < bg) {
                bg = current_gradient;
                temp++;
            }
        }
        bg = numeric_limits<int>::min();
        for (int j = i + 1; j < n; j++) {
            double current_gradient = getGradient(i, buildings[i], j, buildings[j]);
            if (current_gradient > bg) {
                bg = current_gradient;
                temp++;
            }
        }
        max_count = max(max_count, temp);
    }

    return max_count;
}

int main(void) {
    int n;
    cin >> n;

    vector<int> buildings (n, 0);
    input(buildings, n);

    int result = solve(buildings, n);
    cout << result << endl;

    return 0;
}