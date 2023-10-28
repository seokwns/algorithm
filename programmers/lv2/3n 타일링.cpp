#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int mod = 1000000007;
    
    if (n%2 == 1) return 0;
    
    vector<long long> a(n + 1, 0);
    a[0] = 1;
    a[2] = 3;
    a[4] = 11;
    a[6] = 41;
    
    for (int i = 8; i <= n; i += 2) {
        a[i] = ((4 * a[i - 2]) % mod - (a[i - 4]) % mod + mod) % mod;
    }
    
    answer = a[n];
    return answer;
}