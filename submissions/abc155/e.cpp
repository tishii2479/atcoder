#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    string s;
    cin >> s;
    string t = "";
    int n = s.length();
    int isBig = 1;
    int isEqual = 0;
    for (int i = 0; i < s.length(); i++) {
        int si = s[i] - '0';
        int ti = '9' - s[i];
        int tempBig = isBig;
        int tempEqual = isEqual;
        isBig = min(tempEqual + si + 1, tempBig + ti);
        isEqual = min(tempEqual + si, tempBig + ti + 1);
        // cout << isBig << " " << isEqual << endl;
    }
    cout << min(isBig + 1, isEqual) << endl;
}