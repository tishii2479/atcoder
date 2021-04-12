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
    int n;
    cin >> n;
    ll sum = 0;
    bool flag = true;
    vector<ll> a(n);
    vector<ll> b(n);
    ll mn = INF;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        if (a[i] != b[i])
            flag = false;
        sum += a[i];
        if (a[i] > b[i]) {
            mn = min(mn, b[i]);
        }
    }
    if (flag) {
        cout << 0 << endl;
        return 0;
    }
    cout << sum - mn << endl;
}