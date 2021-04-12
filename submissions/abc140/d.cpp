#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) {
            cnt++;
        }
    }
    cout << min(n - 1, n - (cnt - k * 2) - 1) << endl;
}