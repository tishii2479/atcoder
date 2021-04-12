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
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
        sort(s[i].begin(), s[i].end());
    map<string, ll> st;
    for (int i = 0; i < n; i++)
        st[s[i]]++;
    ll ans = 0;
    for (auto si : st) {
        ans += si.second * (si.second - 1) / 2;
    }
    cout << ans << endl;
}