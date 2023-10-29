#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {0, 0};
    
    int left = 0;
    int right = 0;
    int sum = sequence[0];
    int len = 1000000000;
    
    while (left <= right && right < sequence.size()) {
        if (sum < k) {
            right++;
            sum += sequence[right];
        }
        else if (sum == k) {
            int current_length = right - left + 1;
            if (len > current_length) {
                answer = {left, right};
                len = current_length;
            }
            else if (len == current_length) {
                if (answer[0] > left) {
                    answer = {left, right};
                }
            }
            sum -= sequence[left];
            left++;
        }
        else {
            sum -= sequence[left];
            left++;
        }
    }
    
    return answer;
}