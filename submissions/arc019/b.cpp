#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 29;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    string s;
    cin >> s;
    int n = s.length();
    int diff = 0;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1])
            diff++;
    }
    if (diff >= 2) {
        cout << n * 25 << endl;
    } else if (diff == 0 and n % 2 == 1) {
        cout << (n - 1) * 25 << endl;
    } else {
        cout << n * 25 - diff * 2 << endl;
    }
}