#include <bits/stdc++.h>
using namespace std;

int main() {
    string x;
    cin >> x;
    char c = x[x.length() - 3];
    string t = "";
    int cur = 0;
    while (x[cur] != '.') t += x[cur++];
    int ans = stoi(t);
    if (c <= '4') {
        cout << ans << endl;
    } else {
        cout << ans + 1 << endl;
    }
}
