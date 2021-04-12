#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define MOD 1000000007
// #define MOD 998244353
const ll INF = 1ll << 60;
const int inf = 1 << 29;
int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> A(n);
    vector<ll> B(m);
    for (ll i = 0; i < n; i++)
        cin >> A[i];
    for (ll i = 0; i < m; i++)
        cin >> B[i];
    ll t = 0;
    for (int i = 0; i < m; i++)
        t += B[i];
    int j = m;
    int ans = 0;
    for (int i = 0; i < n + 1; i++) {
        while (j > 0 and t > k) {
            j--;
            t -= B[j];
        }
        if (t > k)
            break;
        ans = max(ans, i + j);
        if (i == n)
            break;
        t += A[i];
    }
    cout << ans << endl;
    return 0;
}