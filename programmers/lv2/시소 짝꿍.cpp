#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    int size = weights.size();
    
    vector<int> ws(1001, 0);
    vector<int> mws(4001, 0);
    
    for (int i = 0; i < size; i++) {
        int iter = weights[i];
        int m2 = iter * 2;
        int m3 = iter * 3;
        int m4 = iter * 4;
        
        answer += mws[m2];
        answer += mws[m3];
        answer += mws[m4];
        
        if (ws[iter] > 0) {
            answer -= ws[iter] * 2;
        }
        
        ws[iter]++;
        mws[m2]++;
        mws[m3]++;
        mws[m4]++;
    }
    
    return answer;
}