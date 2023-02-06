#include <iostream>
#include <vector>

using namespace std;


vector<int> getAncestors(int n) {
    vector<int> ancestors;
    ancestors.push_back(n);
    int i = n;

    while(i > 1) {
        if (i % 2 == 0) {
            i = i / 2;
            ancestors.push_back(i);
        }
        if (i % 2 == 1) {
            i = (i - 1) / 2;
            ancestors.push_back(i);
        }
    }
    ancestors.push_back(1);
    return ancestors;
}

vector<int> getCommonAncestors(int n, int m) {
    vector<int> n_ancestors = getAncestors(n);
    vector<int> m_ancestors = getAncestors(m);
    vector<int> common_ancestors;

    for (auto n_ancestor : n_ancestors) {
        bool finded = false;
        for (auto m_ancestor : m_ancestors) {
            if (n_ancestor == m_ancestor) finded = true;
        }
        if (finded) common_ancestors.push_back(n_ancestor);
    }

    return common_ancestors;
}


int getGreatestCommonAncesetor(int n, int m) {
    vector<int> common_ancestors = getCommonAncestors(n, m);
    int result = common_ancestors[0];
    for (auto ancestor : common_ancestors) {
        if (result < ancestor) result = ancestor;
    }
    return result;
}

int main(void) {
    int test_cases;
    cin >> test_cases;

    vector<int> results;
    for (int i = 0; i < test_cases; i++) {
        int n, m;
        cin >> n >> m;
        results.push_back(getGreatestCommonAncesetor(n, m));
    }

    for (auto i : results) {
        cout << 10 * i << "\n";
    }

    return 0;
}
