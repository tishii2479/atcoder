#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
vector<ll> a, b;
bool solve() {
    cin >> n;
    vector<vector<ll>> c(n, vector<ll>(n));
    a.resize(n), b.resize(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
            sum += c[i][j];
        }
    if (sum % n != 0)
        return false;
    int mnidx = 0;
    for (int i = 0; i < n; i++)
        if (c[mnidx][0] > c[i][0])
            mnidx = i;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++)
            if (c[i][j + 1] - c[i][j] != c[mnidx][j + 1] - c[mnidx][j])
                return false;
    for (int i = 0; i < n; i++)
        b[i] = c[mnidx][i];
    for (int i = 0; i < n; i++)
        a[i] = c[i][0] - c[mnidx][0];
    return true;
}
int main() {
    if (solve() == false) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
        for (int i = 0; i < n; i++)
            cout << b[i] << " ";
        cout << endl;
    }
}