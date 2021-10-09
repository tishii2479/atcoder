#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    int k;
    string a, b;
    cin >> k >> a >> b;

    ll va = 0, vb = 0;
    for (int i = 0; i < a.length(); i++) {
        va *= k;
        va += a[i] - '0';
    }
    for (int i = 0; i < b.length(); i++) {
        vb *= k;
        vb += b[i] - '0';
    }

    cout << va * vb << endl;
}
