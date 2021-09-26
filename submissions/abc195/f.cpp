#include <bits/stdc++.h>
using namespace std;

vector<bool> isPrime;

void sieve(size_t max) {
    if (max + 1 > isPrime.size()) {
        isPrime.resize(max + 1, true);
    }
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i <= max; ++i)
        if (isPrime[i])
            for (size_t j = 2; i * j <= max; ++j)
                isPrime[i * j] = false;
}

int main() {
    using ll = long long;
    ll a, b;
    cin >> a >> b;

    sieve(100);
    vector<int> p;

    for (int i = 2; i <= 72; i++) {
        if (isPrime[i]) p.push_back(i);
    }

    const int N = p.size();

    vector<ll> dp(1 << N, 0);
    dp[0] = 1;

    for (ll i = a; i <= b; i++) {
        int mask = 0;
        for (int j = 0; j < N; j++) {
            if (i % p[j] == 0) mask |= (1 << j);
        }

        for (int bit = 0; bit < (1 << N); bit++) {
            // use
            if (bit & mask) continue;
            dp[bit | mask] += dp[bit];
        }
    }

    ll ans = 0;
    for (int i = 0; i < (1 << N); i++) ans += dp[i];
    cout << ans << endl;
}
