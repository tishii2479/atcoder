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
    ll a, b, n;
    cin >> a >> b >> n;
    ll x = min(n, b - 1);
    cout << a * x / b - a * (x / b) << endl;
}