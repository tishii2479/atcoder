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
    double ans = 0;
    for (int i = 1; i < n; i++) {
        ans += (double)(n) / (n - i);
    }
    printf("%.15lf\n", ans);
}