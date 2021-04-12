#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b) {
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
int main() {
    int n;
    ll X;
    cin >> n >> X;
    vector<ll> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    ll gc = abs(x[0] - X);
    for (int i = 0; i < n; i++)
        gc = gcd(gc, abs(x[i] - X));
    cout << gc << endl;
}