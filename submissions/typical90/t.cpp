#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll m_pow(ll a, ll b) {
    ll res = 1;
    for (int i = 1; i <= b; i++) res *= a;
    return res;
}

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << (a < m_pow(c, b) ? "Yes" : "No") << endl;
}
