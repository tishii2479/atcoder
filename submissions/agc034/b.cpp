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
    ll ans = 0;
    vector<int> acnt(s.length(), 0);
    for (int i = 0; i < s.length(); i++) {
        if (i > 1 and s[i] == 'C' and s[i - 1] == 'B' and s[i - 2] == 'A') {
            // found abc
            ans += acnt[i - 2];
            acnt[i] = acnt[i - 2];
            s[i] = 'A';
        } else if (s[i] == 'A')
            acnt[i] = acnt[max(0, i - 1)] + 1;
        else
            acnt[i] = 0;
    }
    cout << ans << endl;
}