#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    string s;
    cin >> s;
    vector<ll> cnt(26, 0);
    ll n = s.length();
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
    }
    ll ans = n * (n - 1) / 2;
    for (int i = 0; i < 26; i++) {
        ans -= cnt[i] * (cnt[i] - 1) / 2;
    }
    cout << ans + 1 << endl;
}