#include <iostream>
#include <queue>
using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    priority_queue<int> arr;
    queue<int> result;
    int n, input;

    cin >> n;
    while(n--) {
        cin >> input;
        if (input == 0) {
            if (arr.empty()) result.push(0);
            else {
                result.push(arr.top());
                arr.pop();
            }
        }
        else {
            arr.push(input);
        }
    }

    while(!result.empty()) {
        cout << result.front() << "\n";
        result.pop();
    }

    return 0;
}