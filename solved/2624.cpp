#include <iostream>
#include <vector>
using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int price;
    cin >> price;

    int types;
    cin >> types;

    vector<int> coins;
    vector<int> counts;
    vector<int> dp (price + 1, 0);
    vector<int> previous (price + 1, 0);
    dp[0] = 1;
    previous[0] = 1;

    int coin_price, coin_count;
    for (int i = 0; i < types; i++) {
        cin >> coin_price >> coin_count;
        coins.push_back(coin_price);
        counts.push_back(coin_count);
    }

    for (int i = 0; i < coins.size(); i++) {
        for (int x = 0; x <= price; x++) {
            if (previous[x] != 0) {
                for (int j = 1; j <= counts[i]; j++) {
                    if (x + coins[i] * j <= price) {
                        dp[x + coins[i] * j] += previous[x];
                    }
                }
            }
        }
        dp[0] = 0;
        for (int j = 1; j <= price; j++) {
            previous[j] += dp[j];
            dp[j] = 0;
        }
    }

    cout << previous[price] << endl;
    return 0;
}