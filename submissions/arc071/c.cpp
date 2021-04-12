#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    string s, t;
    cin >> s >> t;
    int q;
    cin >> q;
    vector<int> sa(s.length() + 1, 0);
    vector<int> sb(s.length() + 1, 0);
    vector<int> ta(t.length() + 1, 0);
    vector<int> tb(t.length() + 1, 0);
    for (int i = 0; i < s.length(); i++) {
        sa[i + 1] = sa[i] + (s[i] == 'A');
        sb[i + 1] = sb[i] + (s[i] == 'B');
    }
    vector<string> res;
    for (int i = 0; i < t.length(); i++) {
        ta[i + 1] = ta[i] + (t[i] == 'A');
        tb[i + 1] = tb[i] + (t[i] == 'B');
    }
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int before_a = sa[b] - sa[a - 1];
        int before_b = sb[b] - sb[a - 1];
        int after_a = ta[d] - ta[c - 1];
        int after_b = tb[d] - tb[c - 1];
        // cout << before_a << " " << before_b << " " << after_a << " " << after_b << endl;
        before_b += ((before_a % 3 + 3) - (after_a % 3)) * 2;
        if (before_b % 3 == after_b % 3)
            res.push_back("YES");
        else
            res.push_back("NO");
    }
    for (string r : res) {
        cout << r << endl;
    }
}