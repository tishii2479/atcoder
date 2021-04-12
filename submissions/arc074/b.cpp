#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n;
    cin >> n;
    n *= 3;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> sum_left(n / 3 + 1, 0);
    multiset<ll> st_left;
    for (int i = 0; i < n / 3; i++) {
        sum_left[0] += a[i];
        st_left.insert(a[i]);
    }
    // for (int s: st_left) {
    //     cout << s << " ";
    // }
    // cout << endl;
    for (int i = 0; i < n / 3; i++) {
        int j = n / 3 + i;
        // cout << i << " " << a[j] << " " << *st_left.begin() << endl;
        if (a[j] > *st_left.begin()) {
            sum_left[i + 1] = sum_left[i] - *st_left.begin() + a[j];
            st_left.erase(st_left.begin());
            st_left.insert(a[j]);
        } else {
            sum_left[i + 1] = sum_left[i];
        }
    }
    vector<ll> sum_right(n / 3 + 1, 0);
    multiset<ll, greater<ll>> st_right;
    reverse(a.begin(), a.end());
    for (int i = 0; i < n / 3; i++) {
        sum_right[0] += a[i];
        st_right.insert(a[i]);
    }
    for (int i = 0; i < n / 3; i++) {
        int j = n / 3 + i;
        if (a[j] < *st_right.begin()) {
            sum_right[i + 1] = sum_right[i] - *st_right.begin() + a[j];
            st_right.erase(st_right.begin());
            st_right.insert(a[j]);
        } else {
            sum_right[i + 1] = sum_right[i];
        }
    }
    ll ans = -INF;
    for (int i = 0; i <= n / 3; i++) {
        // cout << sum_left[i] << " " << sum_right[n / 3 - i] << endl;
        ans = max(ans, sum_left[i] - sum_right[n / 3 - i]);
    }
    cout << ans << endl;
}