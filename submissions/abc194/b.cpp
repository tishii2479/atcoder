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
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    ll same = INF;
    for (int i = 0; i < n; i++)
        same = min(same, a[i] + b[i]);
    ll betu = INF;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            betu = min(betu, max(a[i], b[j]));
        }
    cout << min(betu, same) << endl;
}