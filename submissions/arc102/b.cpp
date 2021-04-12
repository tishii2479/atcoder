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
    int l;
    cin >> l;
    vector<pair<pint, int>> res;
    int pow2[30];
    pow2[0] = 1;
    for (int i = 0; i < 28; i++)
        pow2[i + 1] = pow2[i] * 2;
    int n = 0, m;
    int now = 1;
    while (now * 2 <= l) {
        res.push_back({{n, n + 1}, 0});
        res.push_back({{n, n + 1}, now});
        now *= 2;
        n++;
    }
    int tmp = l;
    l -= pow2[n];
    for (int i = n - 1; i >= 0; i--) {
        if (pow2[i] <= l) {
            res.push_back({{i, n}, tmp - l});
            l -= pow2[i];
        }
    }
    cout << n + 1 << " " << res.size() << endl;
    for (auto r : res)
        cout << r.first.first + 1 << " " << r.first.second + 1 << " " << r.second << endl;
}