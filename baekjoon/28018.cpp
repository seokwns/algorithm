#include <iostream>
using namespace std;


int students[1000001];

int main(void) {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int start, end;
    for (int i = 0; i < n; i++) {
        cin >> start >> end;
        students[start]++;
        students[end + 1]--;
    }

    for (int i = 1; i < 1000001; i++) {
        students[i] += students[i - 1];
    }

    int m, when;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> when;
        cout << students[when] << "\n";
    }

    return 0;
}