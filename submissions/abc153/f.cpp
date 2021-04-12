#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n;
    ll d, a;
    cin >> n >> d >> a;
    vector<ll> x(n), h(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> h[i];
    vector<int> ids(n);
    for (int i = 0; i < n; ++i)
        ids[i] = i;
    sort(ids.begin(), ids.end(), [&](int i, int j) { return x[i] < x[j]; });
    vector<long long> nX(n), nH(n);
    for (int i = 0; i < n; ++i)
        nX[i] = x[ids[i]], nH[i] = h[ids[i]];
    x = nX, h = nH;
    vector<ll> s(n + 1, 0);
    ll res = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] < h[i]) {
            ll need = (h[i] - s[i] + a - 1) / a;
            ll right = x[i] + d * 2;
            int id = upper_bound(x.begin(), x.end(), right) - x.begin();
            s[i] += need * a;
            s[id] -= need * a;
            res += need;
        }
        s[i + 1] += s[i];
    }
    cout << res << endl;
}