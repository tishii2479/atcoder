#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#define INF 1000000000000
#define MOD 1000000007
// #define MOD 998244353
using namespace std;
typedef long long ll;
ll dp[101][100010] = {0};
int main() {
    int N, W;
    cin >> N >> W;
    vector<ll> w(N);
    vector<ll> v(N);
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= W; j++) {
            if (j - w[i] >= 0) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - w[i]] + v[i]);
            }
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        }
    }
    cout << dp[N][W] << endl;
}