#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, long long>> prime_factorize(long long n) {
    vector<pair<long long, long long>> res;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p != 0)
            continue;
        int num = 0;
        while (n % p == 0) {
            ++num;
            n /= p;
        }
        res.push_back(make_pair(p, num));
    }
    if (n != 1)
        res.push_back(make_pair(n, 1));
    return res;
}

int main() {
    long long n;
    cin >> n;
    auto primes = prime_factorize(n);

    int ans = 0;
    int prime_cnt = 0;
    for (auto p : primes) prime_cnt += p.second;
    prime_cnt -= 1;
    while (prime_cnt > 0) {
        prime_cnt /= 2;
        ans++;
    }

    cout << ans << endl;
}
