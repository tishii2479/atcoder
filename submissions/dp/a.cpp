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
    int n;
    cin >> n;
    vector<ll> h(n + 1);
    vector<ll> dp(n + 1, INF);
    for (int i = 0; i < n; i++) {
        cin >> h[i + 1];
    }
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (i > 1) {
            dp[i] = min(dp[i], dp[i - 1] + abs(h[i - 1] - h[i]));
        }
        if (i - 2 > 0) {
            dp[i] = min(dp[i], dp[i - 2] + abs(h[i - 2] - h[i]));
        }
    }
    cout << dp[n] << endl;
}