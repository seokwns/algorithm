#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string, int> idx;
    
    for (int i = 0; i < players.size(); i++) {
        idx.insert(pair<string, int> (players[i], i));
    }
    
    for (int i = 0; i < callings.size(); i++) {
        int current = idx.at(callings[i]);
        
        idx[players[current]] -= 1;
        idx[players[current - 1]] += 1;
        
        string tmp = players[current];
        players[current] = players[current - 1];
        players[current - 1] = tmp;
    }
    
    answer = players;
    return answer;
}