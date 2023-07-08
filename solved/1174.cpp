#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void dfs(vector<long long>& decs, int nums[10], long long sum, int idx) {
    if (find(decs.begin(), decs.end(), sum) == decs.end()) {
        decs.push_back(sum);
    }
    
    if (idx >= 10) {
        return;
    }

    dfs(decs, nums, sum * 10 + nums[idx], idx + 1);
    dfs(decs, nums, sum, idx + 1);
}

int main(void) {
    int n;
    cin >> n;

    if (n > 1023) {
        cout << -1 << endl;
    }
    else {
        int nums[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
        vector<long long> decs;
        dfs(decs, nums, 0, 0);
        sort(decs.begin(), decs.end());
        cout << decs[n - 1] << endl;
    }
    
    return 0;
}