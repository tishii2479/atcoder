#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string s[3];
set<char> st;
void solve() {
    vector<char> cc(st.size());
    int i = 0;
    for (char c : st) cc[i++] = c;
    vector<int> v;
    for (int i = 0; i < 10; i++) v.push_back(i);
    do {
        unordered_map<char, int> mp;
        for (int i = 0; i < 10; i++) {
            if (i < cc.size()) {
                mp[cc[i]] = v[i];
            }
        }
        ll n[3];
        bool flag = false;
        for (int i = 0; i < 3; i++) {
            ll cur = 0;
            for (int j = 0; j < s[i].length(); j++) {
                if (j == 0 and mp[s[i][j]] == 0) {
                    flag = true;
                    break;
                }
                cur = cur * 10 + mp[s[i][j]];
            }
            n[i] = cur;
        }
        if (flag) continue;
        if (n[0] + n[1] == n[2]) {
            for (int i = 0; i < 3; i++) cout << n[i] << endl;
            exit(0);
        }
    } while (next_permutation(v.begin(), v.end()));
}
int main() {
    for (int i = 0; i < 3; i++) cin >> s[i];
    for (int i = 0; i < 3; i++) {
        for (char c : s[i]) st.insert(c);
    }
    if (st.size() > 10) {
        cout << "UNSOLVABLE" << endl;
        return 0;
    }
    solve();
    cout << "UNSOLVABLE" << endl;
}