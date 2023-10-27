#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end(), compare);
    
    int bound = -1;
    
    for (int i = 0; i < targets.size(); i++) {
        int start = targets[i][0];
        int end = targets[i][1];
        
        if (bound <= start) {
            bound = end;
            answer++;
        }
    }
    
    return answer;
}