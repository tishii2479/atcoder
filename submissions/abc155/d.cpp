#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 61;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> pos;
    vector<ll> neg;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        if (a > 0)
            pos.push_back(a);
        else if (a < 0)
            neg.push_back(a);
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    if (k <= pos.size() * neg.size()) {
        // answer is negative
        ll left = -INF;
        ll right = 1;
        while (right - left > 1) {
            ll x = (left + right) / 2;
            ll cnt = 0;
            for (int i = 0; i < pos.size(); i++) {
                int l = -1;
                int r = neg.size();
                while (r - l > 1) {
                    int m = (r + l) / 2;
                    if (pos[i] * neg[m] > x)
                        r = m;
                    else
                        l = m;
                }
                cnt += r;
            }
            if (cnt >= k)
                right = x;
            else
                left = x;
        }
        cout << right << endl;
        return 0;
    }
    k -= pos.size() * neg.size();
    ll zero = n - pos.size() - neg.size();
    ll zerocnt = n * (n - 1) / 2 - (n - zero) * (n - zero - 1) / 2;
    if (k <= zerocnt) {
        cout << 0 << endl;
        return 0;
    }
    k -= zerocnt;
    // answer is positive
    ll left = -1;
    ll right = INF;
    for (int i = 0; i < neg.size(); i++)
        neg[i] = -neg[i];
    reverse(neg.begin(), neg.end());
    while (right - left > 1) {
        ll x = (right + left) / 2;
        ll cnt = 0;
        ll t = 0;
        for (int i = 0; i < pos.size(); i++) {
            int l = -1;
            int r = pos.size();
            while (r - l > 1) {
                int m = (r + l) / 2;
                if (pos[m] * pos[i] > x)
                    r = m;
                else
                    l = m;
            }
            cnt += r;
            if (pos[i] * pos[i] <= x)
                t++;
        }
        for (int i = 0; i < neg.size(); i++) {
            int l = -1;
            int r = neg.size();
            while (r - l > 1) {
                int m = (r + l) / 2;
                if (neg[m] * neg[i] > x)
                    r = m;
                else
                    l = m;
            }
            cnt += r;
            if (neg[i] * neg[i] <= x)
                t++;
        }
        ll res = (cnt - t) / 2;
        if (res >= k)
            right = x;
        else
            left = x;
    }
    cout << right << endl;
}