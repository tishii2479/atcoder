#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    string s;
    cin >> s;
    for (int i = 0; i < 3; i++) {
        if (s[i] != s[0]) {
            cout << "Lost" << endl;
            return 0;
        }
    }
    cout << "Won" << endl;
}