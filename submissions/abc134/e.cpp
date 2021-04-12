#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    multiset<ll> s;
    for (int i = 0; i < n; i++) {
        ll now = a[i];
        auto itr = s.lower_bound(now);
        if (itr != s.begin())
            s.erase(--itr);
        s.insert(now);
    }
    cout << s.size() << endl;
}