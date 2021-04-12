#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int n;
void dfs(string s, char mx) {
    if (s.length() == n) {
        cout << s << endl;
    } else {
        for (char c = 'a'; c <= mx; c++) {
            dfs(s + c, ((c == mx) ? (char)(mx + 1) : mx));
        }
    }
}
int main() {
    cin >> n;
    dfs("", 'a');
    return 0;
}