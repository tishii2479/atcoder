#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n, q;
    string s;
    cin >> n >> s >> q;
    set<int> indexes[26];
    for (int i = 0; i < n; i++) {
        int a = s[i] - 'a';
        indexes[a].insert(i);
    }
    vector<int> cnts;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i;
            char c;
            cin >> i >> c;
            i--;
            int a = c - 'a';
            for (int j = 0; j < 26; j++) {
                indexes[j].erase(i);
            }
            indexes[a].insert(i);
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            int cnt = 0;
            // for (int i = 0; i < 26; i++)
            // {
            //     cout << char(i + 'a') << endl;
            //     for (auto j : indexes[i])
            //     {
            //         cout << j << " ";
            //     }
            //     cout << endl;
            // }
            for (int i = 0; i < 26; i++) {
                if (indexes[i].lower_bound(l) == indexes[i].end())
                    continue;
                int ind = *indexes[i].lower_bound(l);
                // cout << char(i + 'a') << " " << ind << endl;
                if (ind <= r) {
                    cnt++;
                }
            }
            // cout << cnt << endl;
            cnts.push_back(cnt);
        }
    }
    for (int i = 0; i < cnts.size(); i++)
        cout << cnts[i] << endl;
}