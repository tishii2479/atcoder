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
    int cnt = 0;
    char now = s[0];
    for (int i = 0; i < s.length(); i++) {
        if (now != s[i]) {
            now = s[i];
            cnt++;
        }
    }
    cout << cnt << endl;
}