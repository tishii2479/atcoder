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
    cin >> s;
    int gcnt = 0;
    int pcnt = 0;
    for (char c : s) {
        if (c == 'g')
            gcnt++;
        else
            pcnt++;
    }
    cout << (gcnt - pcnt) / 2 << endl;
}