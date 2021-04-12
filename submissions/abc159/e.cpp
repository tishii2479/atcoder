#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int h, w, k;
    cin >> h >> w >> k;
    int field[11][1100];
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < w; j++) {
            field[i][j] = s[j] - '0';
        }
    }
    int ans = 1 << 30;
    for (int bits = 0; bits < (1 << (h - 1)); bits++) {
        vector<int> div;
        int cnt = 0;
        bool flag = false;
        for (int i = 0; i < (h - 1); i++) {
            if (bits & (1 << i))
                div.push_back(i);
        }
        cnt += div.size();
        vector<int> cnts(div.size() + 1, 0);
        div.push_back(11);
        int prevx = -1;
        for (int x = 0; x < w; x++) {
            int now = 0;
            for (int y = 0; y < h; y++) {
                cnts[now] += field[y][x];
                if (div[now] == y)
                    now++;
            }
            for (int c : cnts) {
                if (c > k) {
                    if (prevx == x) {
                        flag = true;
                        break;
                    }
                    prevx = x;
                    x--;
                    cnt++;
                    for (int i = 0; i < cnts.size(); i++) {
                        cnts[i] = 0;
                    }
                    break;
                }
            }
            if (flag)
                break;
        }
        if (flag)
            continue;
        ans = min(cnt, ans);
    }
    cout << ans << endl;
}