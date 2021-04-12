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
    int f[110][10];
    int p[110][11];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 10; j++)
            cin >> f[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 11; j++)
            cin >> p[i][j];
    int ans = -(1 << 30);
    for (int bits = 1; bits < (1 << 10); bits++) {
        int score = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < 10; j++) {
                if (f[i][j] == 0)
                    continue;
                if (bits & (1 << j)) {
                    cnt++;
                }
            }
            score += p[i][cnt];
        }
        ans = max(score, ans);
    }
    cout << ans << endl;
}