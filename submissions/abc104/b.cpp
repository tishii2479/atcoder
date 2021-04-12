#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
bool solve(string s) {
    if (s[0] != 'A')
        return false;
    int cnt = 0;
    for (int i = 2; i < s.length() - 1; i++) {
        if (s[i] == 'C')
            cnt++;
    }
    if (cnt != 1)
        return false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] - 'a' < 0 and s[i] != 'A' and s[i] != 'C') {
            return false;
        }
    }
    return true;
}
int main() {
    string s;
    cin >> s;
    if (solve(s)) {
        cout << "AC" << endl;
    } else {
        cout << "WA" << endl;
    }
}