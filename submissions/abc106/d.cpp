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
    int n, m, query;
    cin >> n >> m >> query;
    vector<int> l(m), r(m);
    for (int i = 0; i < m; i++)
        cin >> l[i] >> r[i];
    vector<vector<int>> sums(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++)
        sums[l[i]][r[i]]++;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < n; j++)
            sums[i][j + 1] += sums[i][j];
    for (int j = 0; j <= n; j++)
        for (int i = 0; i < n; i++)
            sums[i + 1][j] += sums[i][j];
    while (query--) {
        int p, q;
        cin >> p >> q;
        cout << sums[q][q] - sums[p - 1][q] - sums[q][p - 1] + sums[p - 1][p - 1] << endl;
    }
}