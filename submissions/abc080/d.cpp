#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n, C;
    cin >> n >> C;
    vector<int> s(n);
    vector<int> t(n);
    vector<int> c(n);
    vector<int> sm(200002, 0);
    for (int i = 0; i < n; i++)
        cin >> s[i] >> t[i] >> c[i];
    for (int i = 1; i <= C; i++) {
        vector<int> tt(200002, 0);
        for (int j = 0; j < n; j++)
            if (c[j] == i)
                tt[s[j] * 2 - 1]++, tt[t[j] * 2]--;
        for (int j = 1; j < 200002; j++)
            tt[j] += tt[j - 1];
        for (int j = 0; j < 200002; j++)
            if (tt[j] > 0)
                sm[j]++;
    }
    int mx = 0;
    for (int i = 0; i < 200002; i++) {
        mx = max(mx, sm[i]);
        // cout << sm[i] << endl;
    }
    cout << mx << endl;
}