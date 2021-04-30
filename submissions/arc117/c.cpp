#include <bits/stdc++.h>
using namespace std;

int idx(char c) {
    if (c == 'B') return 0;
    if (c == 'W')
        return 1;
    else
        return 2;
}

char ch(int i) {
    if (i == 0) return 'B';
    if (i == 1)
        return 'W';
    else
        return 'R';
}
using ll = long long;

vector<vector<ll>> com;

void init(ll p) {
    com.assign(p, vector<ll>(p));
    com[0][0] = 1;
    for (ll i = 1; i < p; i++) {
        com[i][0] = 1;
        for (ll j = i; j > 0; j--) {
            com[i][j] = (com[i - 1][j - 1] + com[i - 1][j]) % p;
        }
    }
}

ll nCk(ll n, ll k, ll p) {
    ll ret = 1;
    while (n > 0) {
        ll ni = n % p;
        ll ki = k % p;
        ret *= com[ni][ki];
        ret %= p;
        n /= p;
        k /= p;
    }
    return ret;
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    int p = 3;
    init(p);

    for (int i = 0; i < n; i++) {
        int p2;
        if ((n - 1) % 2 == 0) {
            p2 = 1;
        } else {
            p2 = 2;
        }
        int val = p2 * nCk(n - 1, i, p) * idx(s[i]);
        ans += val;
        ans %= 3;
    }

    cout << ch(ans) << endl;
}
