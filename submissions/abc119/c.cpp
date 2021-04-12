#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
// #define MOD 998244353
const ll INF = 1LL << 60;
const int inf = 1 << 30;
int n, a, b, c;
vector<int> l(10);
int dfs(int cur, int na, int nb, int nc) {
    if (cur == n) {
        if (min({na, nb, nc}) > 0) {
            return abs(a - na) + abs(b - nb) + abs(c - nc) - 30;
        } else {
            return inf;
        }
    }
    int d1 = dfs(cur + 1, na, nb, nc);
    int d2 = dfs(cur + 1, na + l[cur], nb, nc) + 10;
    int d3 = dfs(cur + 1, na, nb + l[cur], nc) + 10;
    int d4 = dfs(cur + 1, na, nb, nc + l[cur]) + 10;
    return min({d1, d2, d3, d4});
}
int main() {
    cin >> n >> a >> b >> c;
    for (int i = 0; i < n; i++)
        cin >> l[i];
    cout << dfs(0, 0, 0, 0) << endl;
}