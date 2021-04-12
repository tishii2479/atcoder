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
    string s;
    cin >> s;
    if (s.length() == 2 and s[0] == s[1]) {
        cout << 1 << " " << 2 << endl;
        return 0;
    }
    for (int i = 0; i < s.length(); i++) {
        if (i < 2)
            continue;
        if (s[i - 2] == s[i] or s[i - 1] == s[i]) {
            cout << i - 1 << " " << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << " " << -1 << endl;
}