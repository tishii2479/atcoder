#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
// #define MOD 998244353
const ll INF = 1LL << 60;
string a, b, aa, bb;
bool isSwappable = false;
void check(string s, int cnt) {
    if (s == bb and (cnt == 3 or isSwappable)) {
        cout << "YES" << endl;
        exit(0);
    }
}
void dfs(string s, int d) {
    if (d == 3)
        return;
    for (int i = 0; i < s.length(); i++)
        for (int j = i + 1; j < s.length(); j++) {
            swap(s[i], s[j]);
            check(s, d + 1);
            dfs(s, d + 1);
            swap(s[i], s[j]);
        }
}
bool solve() {
    vector<int> cnt(26, 0);
    vector<int> acnt(26, 0);
    vector<int> bcnt(26, 0);
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) {
            aa += a[i];
            bb += b[i];
        }
        acnt[a[i] - 'a']++;
        bcnt[b[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
        if (acnt[i] != bcnt[i])
            return false;
    for (int i = 0; i < 26; i++)
        if (acnt[i] > 1)
            isSwappable = true;
    if (aa.length() > 6)
        return false;
    if (aa.length() == 0) {
        if (isSwappable)
            return true;
        else
            return false;
    }
    dfs(aa, 0);
    return false;
}
int main() {
    cin >> a >> b;
    cout << (solve() ? "YES" : "NO") << endl;
}