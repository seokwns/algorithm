#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    priority_queue< int, vector<int>, less<int> > pq;
    for (int i = 0; i < score.size(); i++) {
        pq.push(score[i]);
    }
    
    int counter = 0;
    int bound = k;
    while (!pq.empty()) {
        int cursor = pq.top();
        pq.pop();
        
        counter++;
        bound = min(bound, cursor);
        
        if (counter == m) {
            answer += counter * bound;
            counter = 0;
        }
    }
    
    return answer;
}