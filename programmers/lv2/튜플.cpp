#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> mapper;
    
    string buffer;
    
    for (int i = 1; i < s.length() - 1; i++) {
        if (s[i] != '{' && s[i] != '}' && s[i] != ',') {
            buffer += s[i];
            if (s[i + 1] != ',' && s[i + 1] != '}') {
                continue;
            }
            mapper[stoi(buffer)]++;
        }
        buffer = "";
    }
    
    vector<pair<int, int>> temp (mapper.begin(), mapper.end());
    sort(temp.begin(), temp.end(), compare);
    
    for (pair<int, int> iter : temp) {
        answer.push_back(iter.first);
    }
    
    return answer;
}
