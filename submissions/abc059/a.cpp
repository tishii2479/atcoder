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
    ll ans1 = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (i % 2 == 0) {
            if (sum >= 0) {
                ans1 += sum - (-1);
                sum = -1;
            }
        } else {
            if (sum <= 0) {
                ans1 += 1 - sum;
                sum = 1;
            }
        }
    }
    ll ans2 = 0;
    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (i % 2 == 0) {
            if (sum <= 0) {
                ans2 += 1 - sum;
                sum = 1;
            }
        } else {
            if (sum >= 0) {
                ans2 += sum - (-1);
                sum = -1;
            }
        }
    }
    cout << min(ans1, ans2) << endl;
}