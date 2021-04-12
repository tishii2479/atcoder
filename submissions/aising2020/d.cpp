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
    string x;
    cin >> n >> x;
    int cnt[210000];
    cnt[0] = 0;
    for (int i = 1; i < 210000; i++) {
        int pp = __builtin_popcount(i);
        cnt[i] = cnt[i % pp] + 1;
    }
    reverse(x.begin(), x.end());
    int cn = 0;
    for (int i = 0; i < n; i++)
        if (x[i] == '1')
            cn++;
    int tot1 = 0, p1 = 1;
    int tot2 = 0, p2 = 1;
    for (int i = 0; i < n; i++) {
        if (x[i] == '1') {
            tot1 = (tot1 + p1) % (cn + 1);
            if (2 <= cn)
                tot2 = (tot2 + p2) % (cn - 1);
        }
        p1 = (p1 * 2) % (cn + 1);
        if (2 <= cn)
            p2 = (p2 * 2) % (cn - 1);
    }
    vector<int> ans;
    p1 = 1;
    p2 = 1;
    for (int i = 0; i < n; i++) {
        if (x[i] == '1') {
            if (cn == 1) {
                ans.push_back(0);
            } else {
                int x = (tot2 - p2 + cn - 1) % (cn - 1);
                ans.push_back(cnt[x] + 1);
            }
        } else {
            int x = (tot1 + p1 + cn + 1) % (cn + 1);
            ans.push_back(cnt[x] + 1);
        }
        p1 = (p1 * 2) % (cn + 1);
        if (2 <= cn)
            p2 = (p2 * 2) % (cn - 1);
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; i++)
        cout << ans[i] << endl;
}