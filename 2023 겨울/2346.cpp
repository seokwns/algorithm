#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    deque<pair<int, int>> inputs;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        inputs.push_back(make_pair(i + 1, temp));
    }

    int len = inputs.size();
    int result = 0;

    while(true) {
        cout << inputs.front().first << " ";
        int cnt = inputs.front().second;
        inputs.pop_front();
        if (inputs.empty()) break;
        
        if (cnt >= 0) {
            for (int i = 0; i < cnt - 1; i++) {
                inputs.push_back(inputs.front());
                inputs.pop_front();
            }
        }
        if (cnt < 0) {
            for (int i = 0; i < abs(cnt); i++) {
                inputs.push_front(inputs.back());
                inputs.pop_back();
            }
        }
    }
    cout << endl;

    return 0;
}