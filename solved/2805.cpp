#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void get_input(vector<int>& trees, int tree_count) {
    for (int i = 0; i < tree_count; i++) {
        int tree_length = 0;
        cin >> tree_length;
        trees.push_back(tree_length);
    }
}


long long get_cutted_length(vector<int>& trees, int target_length) {
    long long result = 0;
    int len = trees.size();
    for (int i = 0; i < len; i++) {
        if (trees[i] > target_length) {
            int cutted_length = trees[i] - target_length;
            result += cutted_length;
        }
    }
    return result;
}


int get_maximum_height(vector<int>& trees, int target_length) {
    int low = 0;
    int high = *max_element(trees.begin(), trees.end());
    while(low <= high) {
        int mid = (low + high) / 2;
        long long cutted_length = get_cutted_length(trees, mid);
        if (cutted_length < target_length) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return (low - 1);
}


int main(void) {
    int tree_count = 0;
    int target_length = 0;
    vector<int> trees;
    cin >> tree_count >> target_length;
    get_input(trees, tree_count);
    int maximum_length = get_maximum_height(trees, target_length);
    cout << maximum_length << endl;
    return 0;
}