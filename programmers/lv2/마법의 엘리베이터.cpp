#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while (storey > 0) {
        int mod = storey % 10;
        if (mod < 5) {
            answer += mod;
        }
        else if (mod == 5) {
            answer += 5;
            int tmp = (storey % 100) / 10;
            if (tmp >= 5) storey += 10;
        }
        else {
            answer += 10 - mod;
            storey += 10;
        }
        storey /= 10;
    }
    return answer;
}