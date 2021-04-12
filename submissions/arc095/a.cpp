#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    cin >> n;
    vector<ll> x(n);
    vector<ll> sx(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        sx[i] = x[i];
    }
    sort(x.begin(), x.end());
    int sm = x[n / 2 - 1];
    int lg = x[n / 2];
    for (int i = 0; i < n; i++) {
        int nx = sx[i];
        if (nx <= sm) {
            cout << lg << endl;
        } else {
            cout << sm << endl;
        }
    }
}