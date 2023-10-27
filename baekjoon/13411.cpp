#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


int main(void) {
    int n;
    cin >> n;

    vector<pair<double, int>> times;
    for (int i = 0; i < n; i++) {
        int x;
        int y;
        int v;
        cin >> x >> y >> v;
        double distance = sqrt(pow(x, 2) + pow(y, 2));
        double time = distance / v;
        times.emplace_back(time, i + 1);
    }

    sort(times.begin(), times.end());
    for (int i = 0; i < n; i++) {
        cout << times[i].second << "\n";
    }

    return 0;
}