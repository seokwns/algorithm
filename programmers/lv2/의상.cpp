#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> mapper;
    
    for (int i = 0; i < clothes.size(); i++) {
        vector<string> clothe = clothes[i];
        string name = clothe[0];
        string type = clothe[1];
        
        if (mapper.find(type) != mapper.end()) {
            mapper[type] += 1;
        }
        else {
            mapper[type] = 1;
        }
    }
    
    for (pair<string, int> p : mapper) {
        answer = answer * (p.second + 1);
    }
    
    return answer - 1;
}