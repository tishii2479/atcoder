#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
double f(int x) {
    double res = 1;
    for (int i = 0; i < x; i++)
        res /= 2;
    return res;
}
int main() {
    int n, k;
    cin >> n >> k;
    double ans = 0;
    for (int i = 1; i <= n; i++) {
        int time = 0;
        int tmp = i;
        while (tmp < k)
            tmp *= 2, time++;
        ans += f(time) / n;
    }
    printf("%.15lf\n", ans);
}