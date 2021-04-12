#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
// const int MOD = 998244353;
ll nCk(ll n, ll k) {
    ll res = 1;
    for (ll i = k + 1; i <= n; i++) {
        res *= i;
        res /= (i - k);
    }
    return res;
}
int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end(), greater<ll>());
    vector<pair<pll, ll>> cand;
    for (int i = a; i <= b; i++) {
        ll last = v[i - 1];
        ll include = 0;
        ll total = 0;
        ll sum = 0;
        for (int j = 0; j < n; j++) {
            if (j < i) {
                if (v[j] == last)
                    include++;
                sum += v[j];
            } else if (v[j] == last)
                total++;
        }
        total += include;
        ll cnt = nCk(total, include);
        cand.push_back({{sum, i}, cnt});
    }
    sort(cand.begin(), cand.end(), [&](pair<pll, int> a, pair<pll, int> b) {
        return a.first.first * b.first.second > a.first.second * b.first.first;
    });
    // for (int i = 0; i < cand.size(); i++)
    // {
    //     cout << cand[i].first.first << " " << cand[i].first.second << " " << cand[i].second << endl;
    // }
    double ave = (double)cand[0].first.first / cand[0].first.second;
    ll cnt = 0;
    for (int i = 0; i < cand.size(); i++) {
        pll a = cand[0].first;
        pll b = cand[i].first;
        if (a.first * b.second == a.second * b.first)
            cnt += cand[i].second;
    }
    printf("%.10lf\n", ave);
    cout << cnt << endl;
}