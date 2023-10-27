#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    deque<pair<int, int>> in;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        in.push_back(make_pair(i + 1, temp));
    }

    int len = in.size();
    int result = 0;

    while(true) {
        cout << in.front().first << " ";
        int cnt = in.front().second;
        in.pop_front();
        if (in.empty()) break;
        
        if (cnt >= 0) {
            for (int i = 0; i < cnt - 1; i++) {
                in.push_back(in.front());
                in.pop_front();
            }
        }
        if (cnt < 0) {
            for (int i = 0; i < abs(cnt); i++) {
                in.push_front(in.back());
                in.pop_back();
            }
        }
    }
    cout << endl;

    return 0;
}