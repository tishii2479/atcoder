#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int n, m;
int f(int a, int b) {
    return b >= n;
}
int main() {
    cin >> n >> m;
    int ans = 0;
    for (int i = 1; i * i <= m; i++) {
        if (m % i == 0) {
            int a = m / i;
            int b = i;
            if (f(a, b))
                ans = max(a, ans);
            if (f(b, a))
                ans = max(ans, b);
        }
    }
    cout << ans << endl;
}