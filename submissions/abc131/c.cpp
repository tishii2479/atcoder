#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
ll gcd(ll a, ll b) {
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
ll f(ll n, ll a, ll b) {
    return n - (n / a + n / b - n / lcm(a, b));
}
int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    // cout << f(b, c, d) << " " << f(a - 1, c, d) << endl;
    cout << f(b, c, d) - f(a - 1, c, d) << endl;
}