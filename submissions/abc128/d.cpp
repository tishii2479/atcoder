#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    ll r = min(n, k);
    ll mx = 0;
    for (int a = 0; a <= r; a++) {
        for (int b = 0; b + a <= r; b++) {
            vector<ll> cv;
            ll cur = 0;
            for (int i = 0; i < a; i++)
                cv.push_back(v[i]), cur += v[i];
            for (int i = 0; i < b; i++)
                cv.push_back(v[n - 1 - i]), cur += v[n - 1 - i];
            sort(cv.begin(), cv.end());
            for (int i = 0; i < min(k - a - b, (int)cv.size()); i++) {
                if (cv[i] < 0)
                    cur -= cv[i];
            }
            mx = max(mx, cur);
        }
    }
    cout << mx << endl;
}