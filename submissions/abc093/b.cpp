#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll solve(ll a, ll b) {
    ll v = floorl(sqrtl(a * b - 1));
    ll all = v * 2;
    if (v * (v + 1) >= a * b)
        all--;
    if (a <= v)
        all--;
    if (b <= v)
        all--;
    return all;
}
int main() {
    int q;
    cin >> q;
    vector<ll> res;
    while (q--) {
        ll a, b;
        cin >> a >> b;
        res.push_back(solve(a, b));
    }
    for (auto r : res)
        cout << r << endl;
}