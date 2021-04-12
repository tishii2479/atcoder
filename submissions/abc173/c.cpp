#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<char>> c(h, vector<char>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> c[i][j];
    int ans = 0;
    for (int bit = 0; bit < (1 << h); bit++) {
        vector<int> row;
        for (int i = 0; i < h; i++)
            if (bit & (1 << i))
                row.push_back(i);
        for (int bit2 = 0; bit2 < (1 << w); bit2++) {
            vector<vector<char>> tmp;
            tmp = c;
            vector<int> col;
            for (int j = 0; j < w; j++)
                if (bit2 & (1 << j))
                    col.push_back(j);
            for (int y : row)
                for (int x = 0; x < w; x++)
                    c[y][x] = '.';
            for (int x : col)
                for (int y = 0; y < h; y++)
                    c[y][x] = '.';
            int cnt = 0;
            for (int i = 0; i < h; i++)
                for (int j = 0; j < w; j++)
                    cnt += (c[i][j] == '#');
            if (cnt == k)
                ans++;
            c = tmp;
        }
    }
    cout << ans << endl;
}