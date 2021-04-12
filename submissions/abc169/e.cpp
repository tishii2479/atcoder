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
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (n % 2 == 1) {
        ll l;
        ll r;
        l = a[n / 2];
        r = b[n / 2];
        cout << r - l + 1 << endl;
    } else {
        double l;
        double r;
        l = (double)(a[n / 2 - 1] + a[n / 2]) / 2;
        r = (double)(b[n / 2 - 1] + b[n / 2]) / 2;
        cout << (ll)((r - l) * 2 + 1) << endl;
    }
}