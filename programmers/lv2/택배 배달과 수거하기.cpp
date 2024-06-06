#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int box = 0;
    stack<int> go, back;

    // 집 위치를 스택에 추가
    for (auto elem : deliveries)
        go.push(elem);
    
    for (auto elem : pickups)
        back.push(elem);

    // 가장 먼 곳의 좌표 구하기
    while (!go.empty() && !go.top())
        go.pop();
    while (!back.empty() && !back.top())
        back.pop();

    // 배달 혹은 수거할 집이 없을 때까지 반복
    while (!go.empty() || !back.empty()) {
        // 배달이나 수거가 미완료된 집 중 가장 먼 곳 방문
        answer += max(go.size() * 2, back.size() * 2);

        box = 0;
        // cap 공간이 남으면 빈 공간을 채우는 경우 구하기
        while (!go.empty() && box <= cap) {
            // 가장 먼 곳부터 탐색, cap을 넘지 않는 선에서 모두 방문
            if (go.top() + box <= cap) {
                box += go.top();
                go.pop();
            }
            // 넘을 경우, 마지막 방문지 택배는 남은 cap 만큼만 배달
            else {
                go.top() -= (cap - box);
                break;
            }
        }

        // 수거도 마찬가지로 반복
        box = 0;
        while (!back.empty() && box <= cap) {
            if (back.top() + box <= cap) {
                box += back.top();
                back.pop();
            }
            else {
                back.top() -= (cap - box);
                break;
            }
        }
    }
    
    return answer;
}
