#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int n, k;
vector<int> a;
int solve(int x) {
    vector<int> na(n);
    for (int i = 0; i < n; i++)
        na[i] = a[i] % x;
    sort(na.begin(), na.end());
    vector<int> lsum(n + 1, 0);
    vector<int> rsum(n + 1, 0);
    for (int i = 0; i < n; i++)
        lsum[i + 1] = lsum[i] + na[i];
    for (int i = n - 1; i >= 0; i--)
        rsum[i] = rsum[i + 1] + (x - na[i]);
    for (int i = 0; i <= n; i++) {
        if (rsum[i] != lsum[i])
            continue;
        if (lsum[i] <= k)
            return x;
    }
    return -1;
}
int main() {
    cin >> n >> k;
    a.resize(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int ans = 0;
    for (int i = 1; i * i <= sum; i++) {
        if (sum % i != 0)
            continue;
        int a = sum / i;
        int b = i;
        ans = max(ans, solve(a));
        ans = max(ans, solve(b));
    }
    cout << ans << endl;
}