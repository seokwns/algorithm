#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = abs(sequence[0]);
    long long a = 0;
    long long b = 0;
    int size = sequence.size();
    
    for (int i = 0; i < size; i++) {
        int w = 1;
        if (i%2 == 1) w = -1;
        a = max(a + sequence[i] * w, (long long) sequence[i] * w);
        b = max(b + sequence[i] * -w, (long long) sequence[i] * -w);
        answer = max(answer, max(abs(a), abs(b)));
    }
    
    return answer;
}