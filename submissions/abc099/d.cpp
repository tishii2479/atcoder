#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n, C;
    cin >> n >> C;
    int d[31][31];
    int c[510][510];
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < C; j++) {
            cin >> d[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
            c[i][j]--;
        }
    }
    int ans = 1 << 30;
    // i = 0, j = 1, k = 2
    vector<vector<int>> cnts = vector<vector<int>>(3, vector<int>(C, 0));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            int ind = (x + y) % 3;
            cnts[ind][c[y][x]]++;
        }
    }
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < C; j++) {
            for (int k = 0; k < C; k++) {
                if (i == j or j == k or i == k)
                    continue;
                int score = 0;
                for (int c = 0; c < C; c++)
                    score += cnts[0][c] * d[c][i];
                for (int c = 0; c < C; c++)
                    score += cnts[1][c] * d[c][j];
                for (int c = 0; c < C; c++)
                    score += cnts[2][c] * d[c][k];
                ans = min(score, ans);
            }
        }
    }
    cout << ans << endl;
}