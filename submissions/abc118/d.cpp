#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
const string nil = "nil";
void chmax(string &a, string b) {
    if (a == nil)
        a = b;
    else if (a.size() < b.size())
        a = b;
    else if (a.size() == b.size())
        if (a < b)
            a = b;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    vector<int> cnt = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    vector<string> dp(11000, nil);
    dp[0] = "";
    for (int i = 1; i <= n; i++) {
        for (int c : a) {
            if (i - cnt[c] < 0)
                continue;
            if (dp[i - cnt[c]] == nil)
                continue;
            chmax(dp[i], to_string(c) + dp[i - cnt[c]]);
        }
    }
    cout << dp[n] << endl;
}