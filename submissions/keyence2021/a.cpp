#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c(n);
    ll now = 0;
    vector<ll> maxa(n);
    vector<ll> maxb(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            maxa[i] = max(maxa[i - 1], a[i]);
            maxb[i] = max(maxb[i - 1], b[i]);
        } else {
            maxa[i] = a[i];
            maxb[i] = b[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            c[i] = a[i] * b[i];
            continue;
        }
        c[i] = max(c[i - 1], maxa[i] * b[i]);
    }
    for (int i = 0; i < n; i++) {
        cout << c[i] << endl;
    }
}