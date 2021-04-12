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
    ll k;
    cin >> k;
    ll n = 50;
    vector<ll> a(n, n - 1);
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        a[i] += k / n;
    }
    for (int i = 0; i < (k % n); i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                a[j] += n;
            } else {
                a[j]--;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}