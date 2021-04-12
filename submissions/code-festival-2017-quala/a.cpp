#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
string solve(string s) {
    if (s.size() < 4)
        return "No";
    string t = "YAKI";
    for (int i = 0; i < 4; i++)
        if (t[i] != s[i])
            return "No";
    return "Yes";
}
int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
}