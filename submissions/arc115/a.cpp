#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    ll a = 0;
    ll b = 0;
    for (int i = 0; i < n; i++) {
        int diff = 0;
        for (int j = 0; j < m; j++)
            if (s[0][j] != s[i][j])
                diff++;
        if (diff % 2 == 0)
            a++;
        else
            b++;
    }
    cout << a * b << endl;
}