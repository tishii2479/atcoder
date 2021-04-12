#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
ll convert(string s) {
    ll under = 0;
    vector<ll> num;
    for (ll i = s.length() - 1; i >= 0; i--) {
        int a = s[i] - '0';
        if (a >= 0 and a < 10)
            num.push_back(a);
        if (s[i] == '.')
            under = s.length() - i - 1;
    }
    reverse(num.begin(), num.end());
    ll cur = 0;
    for (int i = 0; i < num.size(); i++)
        cur = cur * 10 + num[i];
    for (int i = 0; i < 9 - under; i++)
        cur *= 10;
    return cur;
}
int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> b(n);
    for (int i = 0; i < n; i++)
        b[i] = convert(a[i]);
    vector<vector<ll>> cnt(20, vector<ll>(20, 0));
    for (int i = 0; i < n; i++) {
        int cnt2 = 0, cnt5 = 0;
        while (b[i] % 2 == 0) {
            cnt2++;
            b[i] /= 2;
        }
        while (b[i] % 5 == 0) {
            cnt5++;
            b[i] /= 5;
        }
        cnt2 = min(18, cnt2);
        cnt5 = min(18, cnt5);
        cnt[cnt2][cnt5]++;
    }
    ll ans = 0;
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            for (int k = 0; k < 20; k++)
                for (int l = 0; l < 20; l++) {
                    if (i + k < 18 or j + l < 18)
                        continue;
                    if (cnt[i][j] == 0 or cnt[k][l] == 0)
                        continue;
                    if (i == k and j == l)
                        ans += cnt[i][j] * (cnt[i][j] - 1);
                    else
                        ans += cnt[i][j] * cnt[k][l];
                }
    cout << ans / 2 << endl;
}