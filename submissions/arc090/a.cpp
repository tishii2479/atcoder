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
    int a[2][110];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    vector<int> ue(n + 1, 0);
    vector<int> sita(n + 1, 0);
    for (int i = 0; i < n; i++) {
        ue[i + 1] = ue[i] + a[0][i];
    }
    for (int i = 0; i < n; i++) {
        sita[i + 1] = sita[i] + a[1][i];
    }
    for (int i = 0; i < n; i++) {
        ans = max(ue[i] + sita[n] - sita[i] + a[0][i], ans);
    }
    cout << ans << endl;
}