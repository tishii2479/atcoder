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
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    if (n % 2 == 1) {
        ll ans1 = 0;
        ll ans2 = 0;
        for (int i = 0; i < n; i++) {
            if (i < n / 2 - 1) {
                ans1 += a[i] * -2;
            } else if (i < n / 2 + 1) {
                ans1 += a[i] * -1;
            } else {
                ans1 += a[i] * 2;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i < n / 2) {
                ans2 += a[i] * -2;
            } else if (i < n / 2 + 2) {
                ans2 += a[i] * 1;
            } else {
                ans2 += a[i] * 2;
            }
        }
        ans = max(ans1, ans2);
    } else {
        ll ans1 = 0,
           ans2 = 0;
        for (int i = 0; i < n; i++) {
            if (i < n / 2 - 1) {
                ans1 += a[i] * -2;
            } else if (i == n / 2 - 1) {
                ans1 += a[i] * -1;
            } else if (i == n / 2) {
                ans1 += a[i];
            } else {
                ans1 += a[i] * 2;
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     if (i < n / 2 - 1)
        //     {
        //         ans1 += a[i] * -2;
        //     }
        //     else if (i == n / 2 - 1)
        //     {
        //         ans1 += a[i] * -1;
        //     }
        //     else if (i == n / 2)
        //     {
        //         ans1 += a[i];
        //     }
        //     else
        //     {
        //         ans1 += a[i] * 2;
        //     }
        // }
        ans = max(ans1, ans2);
    }
    cout << ans << endl;
}