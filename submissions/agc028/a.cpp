#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int main() {
    long long n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    long long gc = gcd(n, m);
    long long lc = n * m / gc;
    bool ok = true;

    for (long long i = 0, j = 0; i < n and j < m; i += n / gc, j += m / gc) {
        if (s[i] != t[j]) ok = false;
    }

    if (ok)
        cout << lc << endl;
    else
        cout << -1 << endl;
}
