#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int h, w, n, sr, sc;
string s, t;
bool solve() {
    int left = 0, right = w;
    if (s[n - 1] == 'R')
        right--;
    else if (s[n - 1] == 'L')
        left++;
    for (int i = n - 2; i >= 0; i--) {
        if (t[i] == 'R')
            left = max(0, left - 1);
        else if (t[i] == 'L')
            right = min(right + 1, w);
        if (s[i] == 'R')
            right = right - 1;
        else if (s[i] == 'L')
            left = left + 1;
        if (left >= right)
            return false;
    }
    if (sc < left or sc >= right)
        return false;
    left = 0, right = h;
    if (s[n - 1] == 'U')
        left++;
    else if (s[n - 1] == 'D')
        right--;
    for (int i = n - 2; i >= 0; i--) {
        if (t[i] == 'U')
            right = min(right + 1, h);
        else if (t[i] == 'D')
            left = max(0, left - 1);
        if (s[i] == 'D')
            right = right - 1;
        else if (s[i] == 'U')
            left = left + 1;
        if (left >= right)
            return false;
    }
    if (sr < left or sr >= right)
        return false;
    return true;
}
int main() {
    cin >> h >> w >> n >> sr >> sc;
    cin >> s >> t;
    sr--, sc--;
    cout << (solve() ? "YES" : "NO") << endl;
}