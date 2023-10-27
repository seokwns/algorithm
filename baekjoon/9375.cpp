#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;


void get_dresses(map<string, vector<string>>& dresses) {
    string dress;
    string dress_type;
    cin >> dress >> dress_type;
    dresses[dress_type].push_back(dress);
}


int get_dress_collection(map<string, vector<string>>& dresses) {
    int collection = 1;
    for (auto i = dresses.begin(); i != dresses.end(); i++) {
        int dress_count = i->second.size() + 1;
        collection *= dress_count;
    }
    return (collection - 1);
}


int main(void) {
    int test_case = 0;
    vector<int> results;
    cin >> test_case;
    for (int i = 0; i < test_case; i++) {
        map<string, vector<string>> dresses;
        int dress_count = 0;
        cin >> dress_count;
        for (int j = 0; j < dress_count; j++) {
            get_dresses(dresses);
        }
        int collection = get_dress_collection(dresses);
        results.push_back(collection);
    }
    for (int i = 0; i < test_case; i++) {
        cout << results[i] << endl;
    }
    return 0;
}