#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
ll dp[110000];
int main() {
    int n, m;
    cin >> n >> m;
    set<int> a;
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        a.insert(b);
    }
    dp[0] = 1;
    int now = 0;
    for (int i = 1; i <= n; i++) {
        if (i - 2 >= 0 and a.find(i - 2) == a.end()) {
            dp[i] += dp[i - 2];
        }
        if (i - 1 >= 0 and a.find(i - 1) == a.end()) {
            dp[i] += dp[i - 1];
        }
        dp[i] %= MOD;
    }
    cout << dp[n] << endl;
}