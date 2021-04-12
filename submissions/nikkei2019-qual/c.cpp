#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
const ll INF = 1LL << 60;
// #define MOD 998244353
int main() {
    int n;
    cin >> n;
    vector<pll> dish(n);
    vector<ll> a(n);
    vector<ll> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        dish[i] = {a[i] + b[i], i};
    }
    sort(dish.begin(), dish.end(), greater<pll>());
    ll tp = 0;
    ll ap = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            tp += a[dish[i].second];
        } else {
            ap += b[dish[i].second];
        }
    }
    cout << tp - ap << endl;
}