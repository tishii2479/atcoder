#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int n;
string s[310];
int solve(int a, int b) {
    char t[310][310];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            t[i][j] = s[(i - a + n) % n][(j - b + n) % n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (t[i][j] != t[j][i])
                return 0;
    return 1;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    int ans = 0;
    for (int a = 0; a < n; a++)
        ans += solve(a, 0) * n;
    cout << ans << endl;
}