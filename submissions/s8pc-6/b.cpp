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
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    ll ans = INF;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            ll start = a[i];
            ll end = b[j];
            ll sum = 0;
            for (int k = 0; k < n; k++)
                sum += abs(start - a[k]) + abs(a[k] - b[k]) + abs(b[k] - end);
            ans = min(ans, sum);
        }
    cout << ans << endl;
}