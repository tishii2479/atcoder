#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int n, q;
int a[210000], b[210000];
multiset<int> k[210000];
int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        k[b[i]].insert(a[i]);
    }
    multiset<int> kings;
    for (int i = 0; i < 210000; i++) {
        if (k[i].size() > 0)
            kings.insert(*k[i].rbegin());
    }
    while (q--) {
        int c, d;
        cin >> c >> d;
        c--;
        kings.erase(kings.find(*k[b[c]].rbegin()));
        k[b[c]].erase(k[b[c]].find(a[c]));
        if (k[b[c]].size() > 0)
            kings.insert(*k[b[c]].rbegin());
        b[c] = d;
        if (k[d].size() > 0)
            kings.erase(kings.find(*k[d].rbegin()));
        k[d].insert(a[c]);
        kings.insert(*k[d].rbegin());
        cout << *kings.begin() << endl;
    }
}