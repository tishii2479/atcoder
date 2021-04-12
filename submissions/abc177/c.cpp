#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int main() {
    int n;
    cin >> n;
    ll ans = 0;
    vector<int> a(n);
    vector<ll> b(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i + 1] = b[i] + a[i];
    }
    for (int i = 0; i < n; i++) {
        ll sum = (b[n] - b[i + 1]) % MOD;
        ans += a[i] * sum;
        ans %= MOD;
    }
    cout << ans << endl;
}