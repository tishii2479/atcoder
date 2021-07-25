#include <bits/stdc++.h>
using namespace std;

string str;
int k;
bool found = false;

void dfs(int last, int cur = 0, int add = 0) {
    if (found) return;

    if (cur == str.length()) {
        if (add == 0) {
            cout << k << endl;
            found = true;
        }
        return;
    }

    for (int i = 0; i <= last * 3; i++) {
        int val = i + add;
        int nxt_add = val / 10;
        int digit = val % 10;
        int l = min(last, i);
        if (digit == (str[cur] - '0')) {
            dfs(l, cur + 1, nxt_add);
        }
    }
}

void solve() {
    long long n;
    cin >> n;

    str = to_string(n);
    reverse(str.begin(), str.end());
    found = false;

    for (k = 1; found == false; k++) {
        dfs(k);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
