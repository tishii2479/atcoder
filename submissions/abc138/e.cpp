#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int nex[210000][30];
int main() {
    string s, t;
    cin >> s >> t;
    int a = s.length();
    int b = t.length();
    s = s + s;
    for (int j = 0; j < 26; j++) {
        nex[2 * a][j] = 2 * a;
    }
    for (int i = 2 * a - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            nex[i][j] = nex[i + 1][j];
        }
        nex[i][s[i] - 'a'] = i + 1;
    }
    ll ans = 0;
    for (int i = 0; i < b; i++) {
        int u = t[i] - 'a';
        int x = ans % a;
        if (nex[x][u] == 2 * a) {
            cout << -1 << endl;
            return 0;
        }
        ans += nex[x][u] - x;
    }
    cout << ans << endl;
}