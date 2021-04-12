#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n), y(n), c(n);
    for (int i = 0; i < n; i++) {
        char sc;
        cin >> x[i] >> y[i] >> sc;
        x[i] %= k * 2;
        y[i] %= k * 2;
        c[i] = (sc == 'W');
    }
    vector<vector<int>> white(k, vector<int>(k, 0));
    int bnum = 0;
    for (int i = 0; i < n; i++) {
        c[i] += x[i] / k + y[i] / k;
        c[i] %= 2;
        x[i] %= k;
        y[i] %= k;
        white[x[i]][y[i]] += (c[i] ? 1 : -1);
        if (c[i] == 0)
            bnum++;
    }
    for (int x = 0; x < k; x++)
        for (int y = 1; y < k; y++)
            white[x][y] += white[x][y - 1];
    for (int y = 0; y < k; y++)
        for (int x = 1; x < k; x++)
            white[x][y] += white[x - 1][y];
    int ans = 0;
    for (int x = 0; x < k; x++)
        for (int y = 0; y < k; y++) {
            int w = white[k - 1][k - 1] - white[x][k - 1] - white[k - 1][y] + white[x][y] * 2 + bnum;
            ans = max(ans, max(w, n - w));
        }
    cout << ans << endl;
}