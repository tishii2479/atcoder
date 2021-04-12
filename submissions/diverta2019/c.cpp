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
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    int cnt = 0;
    int alast = 0;
    int bfirst = 0;
    int both = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < s[i].length(); j++) {
            if (s[i][j - 1] == 'A' and s[i][j] == 'B')
                cnt++;
        }
        if (s[i][s[i].length() - 1] == 'A')
            alast++;
        if (s[i][0] == 'B')
            bfirst++;
        if (s[i][s[i].length() - 1] == 'A' and s[i][0] == 'B')
            both++;
    }
    if (both == alast and both == bfirst)
        alast--;
    cout << cnt + max(0, min({alast, bfirst, n - 1})) << endl;
}