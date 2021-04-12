#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>
// #define MOD 1000000007
#define MOD 998244353
using namespace std;
typedef long long ll;
int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(k);
    for (int i = 0; i < k; i++)
        cin >> v[i].first >> v[i].second;
    vector<ll> dp(n);
    vector<ll> sdp(n + 1, 0);
    dp[0] = 1;
    sdp[1] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < v.size(); j++) {
            int left = max(0, i - v[j].second);
            int right = max(0, i - v[j].first + 1);
            dp[i] += (sdp[right] - sdp[left] + MOD) % MOD;
        }
        sdp[i + 1] = (sdp[i] + dp[i]) % MOD;
    }
    cout << dp[n - 1] % MOD << endl;
}