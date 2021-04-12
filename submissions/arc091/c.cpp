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
    int n, a, b;
    cin >> n >> a >> b;
    if (b > n - a + 1 or (n + a - 1) / a > b) {
        cout << -1 << endl;
        return 0;
    }
    if (a == 1) {
        for (int i = 1; i <= n; i++)
            cout << n - i + 1 << " ";
        cout << endl;
        return 0;
    } else if (b == 1) {
        for (int i = 1; i <= n; i++)
            cout << i << " ";
        cout << endl;
        return 0;
    }
    for (int i = n - a + 1; i <= n; i++) {
        cout << i << " ";
    }
    int mx = n - a + 1;
    int cnt = (mx - b) / (a - 1);
    for (int i = 0; i < cnt; i++) {
        for (int j = a; j > 0; j--) {
            cout << mx - j - i * a << " ";
        }
    }
    mx = mx - cnt * a;
    b -= cnt + 1;
    if (b > 0)
        for (int i = b; i < mx; i++) {
            cout << i << " ";
        }
    for (int i = b - 1; i > 0; i--) {
        cout << i << " ";
    }
    cout << endl;
}