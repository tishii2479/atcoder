#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
ll calc(ll med, vector<ll> a) {
    ll res = 0;
    for (int i = 0; i < a.size(); i++) {
        res += abs(a[i] - med);
    }
    return res;
}
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= i + 1;
    }
    sort(a.begin(), a.end());
    if (n % 2 == 0) {
        ll med1 = (a[n / 2 - 1] + a[n / 2]) / 2;
        ll med2 = (a[n / 2 - 1] + a[n / 2]) / 2 + 1;
        cout << min(calc(med1, a), calc(med2, a)) << endl;
        ;
    } else {
        ll med = a[n / 2];
        cout << calc(med, a) << endl;
    }
}