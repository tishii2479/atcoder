#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
bool isOk(string s) {
    string a = "";
    for (int i = 0; i < s.length(); i++)
        if (s[i] != 'x')
            a += s[i];
    for (int i = 0; i < a.length() / 2; i++)
        if (a[i] != a[a.length() - i - 1])
            return false;
    return true;
}
int main() {
    string s;
    cin >> s;
    if (isOk(s) == false) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> x;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'x') {
            cnt++;
            continue;
        }
        x.push_back(cnt);
        cnt = 0;
    }
    x.push_back(cnt);
    // for (int i : x)
    //     cout << i << " ";
    // cout << endl;
    ll ans = 0;
    for (int i = 0; i < (x.size() / 2); i++)
        ans += abs(x[i] - x[x.size() - i - 1]);
    cout << ans << endl;
}