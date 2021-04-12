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
    int k;
    cin >> s >> k;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        int a = s[i] - 'a';
        if (a == 0)
            continue;
        if (26 - a <= k) {
            s[i] = 'a';
            k -= 26 - a;
        }
    }
    int last = s[n - 1] - 'a';
    last += k;
    last %= 26;
    s[n - 1] = (char)(last + 'a');
    cout << s << endl;
}