#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long Int;
#define each(i, mp) for (auto &i : mp)
#define rep(i, n) for (Int i = 0; i < n; i++)
#define repd(i, n) for (Int i = n - 1; i >= 0; i--)
#define MOD 1000000007
// #define MOD 998244353
const Int INF = 1LL << 60;
const int inf = 1 << 29;
int main() {
    int n;
    string s;
    cin >> n >> s;
    Int ans = 0;
    vector<int> rsum(n + 1, 0);
    vector<int> gsum(n + 1, 0);
    vector<int> bsum(n + 1, 0);
    int r, g, b = 0;
    rep(i, n) {
        if (s[i] == 'R') {
            r++;
        }
        if (s[i] == 'G') {
            g++;
        }
        if (s[i] == 'B') {
            b++;
        }
        rsum[i + 1] = r;
        gsum[i + 1] = g;
        bsum[i + 1] = b;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (s[i] == s[j])
                continue;
            if ((s[i] == 'R' and s[j] == 'G') or
                (s[i] == 'G' and s[j] == 'R')) {
                ans += bsum[n] - bsum[j + 1];
                if (2 * j - i < n) {
                    if (s[2 * j - i] == 'B')
                        ans--;
                }
            }
            if ((s[i] == 'R' and s[j] == 'B') or
                (s[i] == 'B' and s[j] == 'R')) {
                ans += gsum[n] - gsum[j + 1];
                if (2 * j - i < n) {
                    if (s[2 * j - i] == 'G')
                        ans--;
                }
            }
            if ((s[i] == 'B' and s[j] == 'G') or
                (s[i] == 'G' and s[j] == 'B')) {
                ans += rsum[n] - rsum[j + 1];
                if (2 * j - i < n) {
                    if (s[2 * j - i] == 'R')
                        ans--;
                }
            }
        }
    }
    cout << ans << endl;
}