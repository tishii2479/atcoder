#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
vector<int> e(110, 0);
int num(int n) {
    int cnt = 0;
    for (int i = 0; i < 110; i++) {
        cnt += e[i] >= n - 1 ? 1 : 0;
    }
    return cnt;
}
int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int cur = i;
        for (int j = 2; j <= i; j++) {
            while (cur % j == 0) {
                e[j]++;
                cur /= j;
            }
        }
    }
    int res = num(75) + num(25) * (num(3) - 1) + num(15) * (num(5) - 1) + num(5) * ((num(5) - 1) * (num(3) - 2)) / 2;
    cout << res << endl;
}