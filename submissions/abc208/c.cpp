#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    vector<ll> res(n);

    ll each = k / n;
    ll remain = k % n;
    for (int i = 0; i < n; i++) {
        if (i < remain)
            res[a[i].second] = each + 1;
        else
            res[a[i].second] = each;
    }

    for (ll r : res) cout << r << endl;
}
