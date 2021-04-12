#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
// #define MOD 998244353
const ll INF = 1LL << 60;
int main() {
    int n, m;
    cin >> n >> m;
    vector<pint> ba(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        ba[i] = {b, a};
    }
    sort(ba.begin(), ba.end());
    int x = -1;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int a = ba[i].second;
        int b = ba[i].first;
        if (a > x) {
            ans++;
            x = b - 1;
        }
    }
    cout << ans << endl;
}