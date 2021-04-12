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
    string s;
    cin >> n >> s;
    vector<int> left(n + 1, 0), right(n + 1, 0);
    for (int i = 0; i < n; i++) {
        left[i + 1] = left[i];
        if (s[i] == 'W')
            left[i + 1]++;
    }
    for (int i = n - 1; i >= 0; i--) {
        right[i] = right[i + 1];
        if (s[i] == 'E')
            right[i]++;
    }
    int ans = inf;
    for (int i = 0; i <= n; i++)
        ans = min(ans, left[i] + right[i]);
    cout << ans << endl;
}