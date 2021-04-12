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
    ll w, h, x, y;
    cin >> w >> h >> x >> y;
    int ok = (w == 2 * x and h == 2 * y);
    double s = (double)(w * h) / 2;
    cout << fixed << setprecision(10) << s << " " << ok << endl;
}