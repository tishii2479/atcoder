#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    ll x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<ll> ab;
    vector<ll> a(x);
    vector<ll> b(y);
    vector<ll> c(z);
    for (int i = 0; i < x; i++)
        cin >> a[i];
    for (int i = 0; i < y; i++)
        cin >> b[i];
    for (int i = 0; i < z; i++)
        cin >> c[i];
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            ab.push_back(a[i] + b[j]);
        }
    }
    sort(ab.begin(), ab.end(), greater<ll>());
    sort(c.begin(), c.end(), greater<ll>());
    priority_queue<pair<ll, pint>, vector<pair<ll, pint>>> pq;
    pq.push({ab[0] + c[0], {0, 0}});
    set<pair<ll, pint>> used;
    for (int i = 0; i < k; i++) {
        pair<ll, pint> p = pq.top();
        pq.pop();
        pint pi = p.second;
        if (pi.first + 1 < x * y) {
            pair<ll, pint> p = {ab[pi.first + 1] + c[pi.second],
                                {pi.first + 1, pi.second}};
            if (used.count(p) == 0)
                pq.push(p), used.insert(p);
        }
        if (pi.second + 1 < z) {
            pair<ll, pint> p = {ab[pi.first] + c[pi.second + 1],
                                {pi.first, pi.second + 1}};
            if (used.count(p) == 0)
                pq.push(p), used.insert(p);
        }
        cout << p.first << endl;
    }
}