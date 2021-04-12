#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        string a = "atcoder";
        if (s > a) {
            cout << 0 << endl;
            continue;
        }
        int res = 1 << 30;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a')
                continue;
            if (i == 1)
                res = 1;
            else if (s[i] > 't')
                res = min(res, i - 1);
            else
                res = min(res, i);
        }
        cout << (res < (1 << 30) ? res : -1) << endl;
    }
}