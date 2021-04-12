#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
#define each(i, mp) for (auto &i : mp)
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
const ll INF = 1LL << 60;
const int inf = 1 << 29;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> pair;
    int cnt = 1;
    char now = s[0];
    for (int i = 1; i < n; i++) {
        if (s[i] == now) {
            cnt++;
            continue;
        }
        pair.push_back(cnt);
        cnt = 1;
        now = s[i];
    }
    pair.push_back(cnt);
    int ans = 0;
    vector<int> sums(pair.size() + 1);
    sums[0] = 0;
    for (int i = 0; i < pair.size(); i++) {
        sums[i + 1] = sums[i] + pair[i];
    }
    if (s[0] == '0') {
        for (int i = 0; i < pair.size(); i += 2) {
            int val = sums[min((int)pair.size(), i + 2 * k)] - sums[max(0, i - 1)];
            chmax(ans, val);
        }
    } else {
        for (int i = 0; i < pair.size(); i += 2) {
            int val = sums[min((int)pair.size(), i + 2 * k + 1)] - sums[max(0, i)];
            chmax(ans, val);
        }
    }
    cout << ans << endl;
}