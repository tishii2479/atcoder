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
    int n;
    cin >> n;
    vector<int> a(n + 2, 0);
    vector<int> diff(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i + 1];
    for (int i = 0; i <= n; i++)
        diff[i] = a[i + 1] - a[i];
    for (int i = 0; i <= n; i++)
        sum += abs(diff[i]);
    for (int i = 0; i < n; i++) {
        if ((diff[i] >= 0 and diff[i + 1] >= 0) or (diff[i] <= 0 and diff[i + 1] <= 0)) {
            cout << sum << endl;
            continue;
        }
        int s = sum;
        s -= abs(diff[i]) + abs(diff[i + 1]);
        s += max(abs(diff[i]), abs(diff[i + 1])) - min(abs(diff[i]), abs(diff[i + 1]));
        cout << s << endl;
    }
}