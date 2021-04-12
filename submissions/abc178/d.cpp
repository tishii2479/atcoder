#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#define MOD 1000000007
// #define MOD 998244353
using namespace std;
typedef long long ll;
int main() {
    int s;
    cin >> s;
    vector<int> dp(s + 1);
    dp[0] = 1;
    int x = 0;
    for (int i = 1; i < s + 1; i++) {
        if (i - 3 >= 0) {
            x += dp[i - 3];
            x %= MOD;
        }
        dp[i] = x;
    }
    cout << dp[s] << endl;
}