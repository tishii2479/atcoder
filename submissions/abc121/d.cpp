#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
ll f2(ll a) {
    return (a + 1) / 2 % 2;
}
ll f(ll a) {
    if (a % 2 == 1)
        return f2(a);
    else
        return f2(a + 1) ^ (a + 1);
}
int main() {
    ll a, b;
    cin >> a >> b;
    cout << (f(a - 1) ^ f(b)) << endl;
}