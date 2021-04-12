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
    string s;
    cin >> n >> s;
    vector<ll> white(n + 1, 0);
    vector<ll> black(n + 1, 0);
    for (int i = 0; i < n; i++) {
        white[i + 1] = white[i];
        black[i + 1] = black[i];
        if (s[i] == '#')
            black[i + 1]++;
        else
            white[i + 1]++;
    }
    ll ans = INF;
    for (int i = 0; i <= n; i++) {
        ans = min(ans, black[i] + white[n] - white[i]);
    }
    cout << ans << endl;
}