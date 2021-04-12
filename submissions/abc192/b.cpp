#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
bool isSmall(char c) {
    int a = c - 'a';
    if (a >= 0 and a <= 25)
        return true;
    return false;
}
string solve(string s) {
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (isSmall(s[i]) == false)
                return "No";
        } else {
            if (isSmall(s[i]))
                return "No";
        }
    }
    return "Yes";
}
int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
}