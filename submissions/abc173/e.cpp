#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (int i = 0; i < int(N); ++i)
#define all(a) (a).begin(), (a).end()
typedef long long ll;
const ll MOD = 1e9 + 7;
template <int MOD>
struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0)
            val += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr Fp operator-() const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator+(const Fp &r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator-(const Fp &r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator*(const Fp &r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator/(const Fp &r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp &operator+=(const Fp &r) noexcept {
        val += r.val;
        if (val >= MOD)
            val -= MOD;
        return *this;
    }
    constexpr Fp &operator-=(const Fp &r) noexcept {
        val -= r.val;
        if (val < 0)
            val += MOD;
        return *this;
    }
    constexpr Fp &operator*=(const Fp &r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp &operator/=(const Fp &r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0)
            val += MOD;
        return *this;
    }
    constexpr bool operator==(const Fp &r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator!=(const Fp &r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream &operator<<(ostream &os, const Fp<MOD> &x) noexcept {
        return os << x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0)
            return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1)
            t = t * a;
        return t;
    }
};
using mint = Fp<1000000007>;
int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> s(2e5, 0), f(2e5, 0);
    vector<ll> A;
    ll cntz = 0, cntpl = 0, cntmi = 0;
    rep(i, N) {
        ll a;
        cin >> a;
        A.push_back(abs(a));
        if (a == 0)
            cntz++;
        if (a > 0) {
            s.push_back(a);
            cntpl++;
        }
        if (a < 0) {
            f.push_back(abs(a));
            cntmi++;
        }
    }
    sort(all(A));
    sort(all(s), greater<>());
    sort(all(f), greater<>());
    mint ans = 1;
    if (N == K) {
        rep(i, K) ans *= A[i];
        if (cntmi & 1)
            ans = -ans;
        cout << ans << endl;
        return 0;
    }
    // K < N;
    ll idx[] = {0, 0};
    if (K & 1) {
        if (cntpl > 0)
            ans *= s[idx[0]++];
        else {
            rep(i, K) ans *= A[i];
            ans = -ans;
            cout << ans << endl;
            return 0;
        }
    }
    // 残りの偶数個を決めていく
    ll len = K / 2;
    while (len--) {
        ll tmp[2];
        tmp[0] = s[idx[0]] * s[idx[0] + 1];
        tmp[1] = f[idx[1]] * f[idx[1] + 1];
        if (tmp[0] < tmp[1]) {
            ans *= tmp[1];
            idx[1] += 2;
        } else {
            ans *= tmp[0];
            idx[0] += 2;
        }
    }
    cout << ans << endl;
}