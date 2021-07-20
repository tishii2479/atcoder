#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll g = gcd(a, gcd(b, c));
    cout << a / g + b / g + c / g - 3 << endl;
}
