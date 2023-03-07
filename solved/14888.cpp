#include <iostream>
#include <vector>
using namespace std;


int n;
vector<int> numbers;
vector<int> operators;
int min_value = 1e9, max_value = -1e9;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int input_number;
        cin >> input_number;
        numbers.push_back(input_number);
    }
    for (int i = 0; i < 4; i++) {
        int input_operator;
        cin >> input_operator;
        operators.push_back(input_operator);
    }
}

void update(int value) {
    if (value > max_value) max_value = value;
    if (value < min_value) min_value = value;
}

void dfs(int value, int idx) {
    if (idx == n) {
        update(value);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (operators[i] <= 0) continue;
        operators[i]--;
        switch(i) {
            case 0:
                dfs(value + numbers[idx], idx + 1);
                break;
            case 1:
                dfs(value - numbers[idx], idx + 1);
                break;
            case 2:
                dfs(value * numbers[idx], idx + 1);
                break;
            case 3:
                dfs(value / numbers[idx], idx + 1);
        }
        operators[i]++;
    }
}

void output() {
    cout << max_value << "\n" << min_value << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    dfs(numbers[0], 1);
    output();

    return 0;
}