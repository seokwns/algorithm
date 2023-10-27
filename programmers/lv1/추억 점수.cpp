#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> table;
    
    for (int i = 0; i < name.size(); i++) {
        table.insert(pair<string, int> (name[i], yearning[i]));
    }
    
    for (int i = 0; i < photo.size(); i++) {
        int score = 0;
        for (int j = 0; j < photo[i].size(); j++) {
            map<string, int>::iterator itr = table.find(photo[i][j]);
            if (itr != table.end()) score += itr->second;
        }
        answer.push_back(score);
    }
    
    return answer;
}