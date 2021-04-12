#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    string s;
    int x, y;
    cin >> s >> x >> y;
    vector<int> xm;
    vector<int> ym;
    int c = 0;
    int n = s.length();
    while (c < n and s[c] == 'F')
        c++;
    x -= c;
    s += 'T';
    bool yb = false;
    int cnt = 0;
    for (int i = c; i < n + 1; i++) {
        if (s[i] == 'F') {
            cnt++;
            continue;
        }
        // T
        if (cnt > 0) {
            if (yb) {
                ym.push_back(cnt);
            } else {
                xm.push_back(cnt);
            }
        }
        yb = !yb;
        cnt = 0;
    }
    vector<bool> xdp(8100, false);
    vector<bool> ydp(8100, false);
    xdp[0] = true;
    ydp[0] = true;
    for (int i = 0; i < xm.size(); i++) {
        int dx = xm[i];
        vector<bool> tmp(8100, false);
        for (int j = 0; j < 8100; j++) {
            if (xdp[j] == false)
                continue;
            tmp[dx + j] = tmp[abs(j - dx)] = true;
        }
        swap(xdp, tmp);
    }
    for (int i = 0; i < ym.size(); i++) {
        int dy = ym[i];
        // cout << dy << endl;
        vector<bool> tmp(8100, false);
        for (int j = 0; j < 8100; j++) {
            if (ydp[j] == false)
                continue;
            tmp[dy + j] = tmp[abs(j - dy)] = true;
        }
        swap(tmp, ydp);
    }
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << xdp[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << ydp[i] << " ";
    // }
    // cout << endl;
    cout << ((xdp[abs(x)] and ydp[abs(y)]) ? "Yes" : "No") << endl;
}