#include <bits/stdc++.h>
using namespace std;

char c(int v) {
    if (v < 10) return '0' + v;
    return 'A' + (v - 10);
}

int main() {
    int n;
    cin >> n;
    string t = "";
    if (n == 0) t = "0";
    while (n > 0) {
        int val = n % 36;
        t += c(val);
        n /= 36;
    }

    reverse(t.begin(), t.end());
    cout << t << endl;
}
