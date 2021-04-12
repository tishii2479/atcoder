#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#define INF 1LL << 60
#define MOD 1000000007
// #define MOD 998244353
using namespace std;
typedef long long ll;
int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> h(n);
    vector<ll> dp(n, INF);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
            }
        }
    }
    cout << dp[n - 1] << endl;
}