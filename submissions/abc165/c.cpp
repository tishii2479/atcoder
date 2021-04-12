#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repd(i, n) for (int i = n - 1; i >= 0; i--)
#define MOD 1000000007
// #define MOD 998244353
const Int INF = 1LL << 60;
const int inf = 1 << 29;
int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> A(q), B(q), C(q), D(q);
    rep(i, q) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
        A[i]--;
        B[i]--;
    }
    vector<vector<int>> V[11];
    for (int i = 1; i <= m; i++)
        V[1].push_back({i});
    for (int i = 1; i < n; i++) {
        for (auto &v : V[i]) {
            int b = v.back();
            for (int a = b; a <= m; a++) {
                auto v2 = v;
                v2.push_back(a);
                V[i + 1].push_back(v2);
            }
        }
    }
    int ans = 0;
    for (auto &v : V[n]) {
        int res = 0;
        for (int i = 0; i < q; i++) {
            if (v[B[i]] - v[A[i]] == C[i])
                res += D[i];
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
    return 0;
}