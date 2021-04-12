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
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    int logK = 1;
    while ((1LL << logK) <= k)
        logK++;
    vector<vector<int>> doubling(logK, vector<int>(n));
    for (int i = 0; i < n; i++) {
        doubling[0][i] = a[i];
    }
    for (int j = 0; j < logK - 1; j++)
        for (int i = 0; i < n; i++)
            doubling[j + 1][i] = doubling[j][doubling[j][i]];
    int now = 0;
    for (int j = 0; k > 0; j++) {
        if (k & 1)
            now = doubling[j][now];
        k = k >> 1;
    }
    cout << now + 1 << endl;
}