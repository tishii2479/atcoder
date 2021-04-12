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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll ans = 1;
    vector<int> cnt(3, -1);
    for (int i = 0; i < n; i++) {
        int ind = 0;
        int c = 0;
        for (int j = 0; j < 3; j++) {
            if (cnt[j] + 1 == a[i]) {
                ind = j;
                c++;
            }
        }
        ans *= c;
        ans %= MOD;
        cnt[ind]++;
    }
    cout << ans << endl;
}