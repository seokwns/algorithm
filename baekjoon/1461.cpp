#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int locations[10001];
int main(void) {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> locations[i];
    }

    int dist = 0; // 총 이동거리
    sort(locations, locations + n + 1);

    int pivot = 0;
    for (int i = 0; i <= n; i++) {
        if (locations[i] == 0) {
            pivot = i;
            break;
        }
    }

    for (int i = 0; i < pivot; i += m) {
        dist += abs(locations[i]) * 2;
    }

    for (int i = n; i > pivot; i -= m) {
        dist += abs(locations[i]) * 2;
    }

    dist -= max(abs(locations[0]), abs(locations[n]));

    cout << dist << endl;
    return 0;
}