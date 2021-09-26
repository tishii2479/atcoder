#include <bits/stdc++.h>
using namespace std;

int main() {
    const int n = 26;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    for (int i = 0; i < n; i++) cout << (char)(p[i] + 'a' - 1);
    cout << endl;
}
