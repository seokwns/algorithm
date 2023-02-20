#include <iostream>
#include <queue>
#include <cmath>

using namespace std;


int main(void) {
    int n;
    cin >> n;
    queue<int> people;

    for (int i = 1; i <= n; i++) {
        people.push(i);
    }

    int cursor = 1;
    while(people.size() != 1) {
        long long cp = pow(cursor, 3);
        int rng = cp % people.size() - 1;

        if (rng == -1) rng = people.size() - 1;
        
        for (int i = 0; i < rng; i++) {
            int front_person = people.front();
            people.pop();
            people.push(front_person);
        }
        people.pop();
        cursor++;
    }

    int last_person = people.front();
    cout << last_person << "\n";

    return 0;
}