#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
// #define MOD 998244353
const ll INF = 1LL << 60;
ll n;
void dfs(ll cur, int bits, int &counter) {
    if (cur > n)
        return;
    if (bits == 0b111)
        counter++;
    dfs(cur * 10 + 7, bits | (1 << 2), counter);
    dfs(cur * 10 + 5, bits | (1 << 1), counter);
    dfs(cur * 10 + 3, bits | (1 << 0), counter);
}
int main() {
    cin >> n;
    int counter = 0;
    dfs(0, 0, counter);
    cout << counter << endl;
}