#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    if (a[0] != b[0]) return a[0] > b[0];
    else return a[1] < b[1];
}

int solution(vector<vector<int>> scores) {
    int answer = 1;
    int size = scores.size();
    vector<int> wanho = scores[0];
    int sum = wanho[0] + wanho[1];
    int flag = 0;
    
    sort(scores.begin(), scores.end(), compare);
    
    for (int i = 0; i < size; i++) {
        if (wanho[0] < scores[i][0] && wanho[1] < scores[i][1]) {
            return -1;
        }
        
        if (flag <= scores[i][1]) {
            if (sum < scores[i][0] + scores[i][1]) {
                answer++;
            }
            flag = scores[i][1];
        }
    }
    
    return answer;
}