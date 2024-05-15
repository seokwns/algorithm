#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> pq;
    int deleted = 0;
    
    for (int i = 0; i < operations.size(); i++) {
        if (operations[i][0] == 'I') {
            int value = stoi(operations[i].replace(0, 2, ""));
            pq.push(value);
        }
        else if (operations[i] == "D 1") {
            if (pq.size() - deleted > 0) {
                pq.pop();
            }
        }
        else if (operations[i] == "D -1") {
            if (pq.size() - deleted > 0) {
                deleted++;
            }
        }
    }
    
    int biggest = 0;
    int smallest = 0;
    
    if (pq.size() - deleted > 0) {
        biggest = pq.top();
        pq.pop();
    }
    
    while (pq.size() - deleted > 0) {
        smallest = pq.top();
        pq.pop();
    }

    answer.push_back(biggest);
    answer.push_back(smallest);
    return answer;
}