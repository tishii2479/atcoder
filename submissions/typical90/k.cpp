#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5100;
struct S {
    int d, c;
    ll s;
};
// job, day
ll dp[N][N];

int main() {
    int n;
    cin >> n;
    vector<S> job(n);
    for (int i = 0; i < n; i++) cin >> job[i].d >> job[i].c >> job[i].s;

    sort(job.begin(), job.end(), [&](S a, S b) {
        return a.d < b.d;
    });

    // 配るDP
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < N; j++) {
    //         dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
    //         if (j + job[i].c <= job[i].d)
    //             dp[i + 1][j + job[i].c] = max(dp[i + 1][j + job[i].c], dp[i][j] + job[i].s);
    //     }
    // }

    // 貰うDP
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < N; j++) {
            dp[i + 1][j] = dp[i][j];
            if (j > job[i].d or j - job[i].c < 0) continue;
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - job[i].c] + job[i].s);
        }
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) ans = max(ans, dp[n][i]);
    cout << ans << endl;
}
