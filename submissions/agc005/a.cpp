#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
// #define MOD 998244353
const ll INF = 1LL << 60;
int main() {
    string s;
    cin >> s;
    int n = s.length();
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'S')
            cnt++;
        if (s[i] == 'T') {
            if (cnt > 0) {
                ans++;
                cnt--;
            }
        }
    }
    cout << n - 2 * ans << endl;
}