#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int mxind = max_element(a.begin(), a.end()) - a.begin();
    int mnind = min_element(a.begin(), a.end()) - a.begin();
    int mx = a[mxind];
    int mn = a[mnind];
    vector<pint> res;
    if (mx >= abs(mn)) {
        for (int i = 0; i < n; i++) {
            res.push_back({mxind, i});
            a[i] += a[mxind];
        }
        for (int i = 0; i < n - 1; i++) {
            res.push_back({i, i + 1});
            a[i + 1] += a[i];
        }
    } else {
        for (int i = 0; i < n; i++) {
            res.push_back({mnind, i});
            a[i] += a[mnind];
        }
        for (int i = n - 1; i - 1 >= 0; i--) {
            res.push_back({i, i - 1});
            a[i - 1] += a[i];
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    cout << res.size() << endl;
    for (auto p : res) {
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }
}