#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int sum_left[2100][2100];
int sum_right[2100][2100];
int sum_up[2100][2100];
int sum_down[2100][2100];
int main() {
    int h, w;
    cin >> h >> w;
    string field[h];
    for (int i = 0; i < h; i++)
        cin >> field[i];
    vector<ll> pow2(4100000, 1);
    for (int i = 1; i < 4100000; i++)
        pow2[i] = pow2[i - 1] * 2 % MOD;
    int k = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (field[i][j] == '.')
                k++;
    for (int i = 0; i < h; i++) {
        sum_right[i + 1][w + 1] = 0;
        for (int j = w; j > 0; j--) {
            if (field[i][j - 1] == '.')
                sum_right[i + 1][j] = sum_right[i + 1][j + 1] + 1;
            else
                sum_right[i + 1][j] = 0;
        }
    }
    for (int i = 0; i < h; i++) {
        sum_left[i + 1][0] = 0;
        for (int j = 0; j < w; j++) {
            if (field[i][j] == '.')
                sum_left[i + 1][j + 1] = sum_left[i + 1][j] + 1;
            else
                sum_left[i + 1][j + 1] = 0;
        }
    }
    for (int i = 0; i < w; i++) {
        sum_up[0][i + 1] = 0;
        for (int j = 0; j < h; j++) {
            if (field[j][i] == '.')
                sum_up[j + 1][i + 1] = sum_up[j][i + 1] + 1;
            else
                sum_up[j + 1][i + 1] = 0;
        }
    }
    for (int i = 0; i < w; i++) {
        sum_down[h + 1][i + 1] = 0;
        for (int j = h; j > 0; j--) {
            if (field[j - 1][i] == '.')
                sum_down[j][i + 1] = sum_down[j + 1][i + 1] + 1;
            else
                sum_down[j][i + 1] = 0;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++) {
            if (field[i - 1][j - 1] == '#')
                continue;
            ll s = sum_up[i][j] + sum_down[i][j] + sum_right[i][j] + sum_left[i][j] - 3;
            ans += pow2[k] - pow2[k - s];
            ans %= MOD;
        }
    cout << (ans + MOD) % MOD << endl;
}