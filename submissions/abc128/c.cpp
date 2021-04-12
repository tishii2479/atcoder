#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> k(m);
    vector<int> s[11];
    vector<int> p(m);
    for (int i = 0; i < m; i++) {
        cin >> k[i];
        int a;
        for (int j = 0; j < k[i]; j++) {
            cin >> a;
            a--;
            s[i].push_back(a);
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }
    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        vector<int> on;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j))
                on.push_back(j);
        }
        // for (int o : on)
        // {
        //     cout << o << " ";
        // }
        // cout << endl;
        bool ok = true;
        for (int j = 0; j < m; j++) {
            int cnt = 0;
            for (int l = 0; l < k[j]; l++) {
                for (int o : on) {
                    if (s[j][l] == o) {
                        cnt++;
                        break;
                    }
                }
            }
            if ((cnt % 2) != p[j]) {
                ok = false;
            }
        }
        if (ok)
            ans++;
    }
    cout << ans << endl;
}