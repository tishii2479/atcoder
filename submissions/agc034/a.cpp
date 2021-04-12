#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, a, b, c, d;
string s;
bool solve() {
    if (a > b)
        swap(a, b), swap(c, d);
    a--, b--, c--, d--;
    // a < b
    if (c < d) {
        for (int i = a; i <= c and i + 1 < n; i++)
            if (s[i] == '#' and s[i + 1] == '#')
                return false;
        for (int i = b; i <= d and i + 1 < n; i++)
            if (s[i] == '#' and s[i + 1] == '#')
                return false;
    } else {
        for (int i = a; i <= c and i + 1 < n; i++)
            if (s[i] == '#' and s[i + 1] == '#')
                return false;
        for (int i = b; i <= d and i + 1 < n; i++)
            if (s[i] == '#' and s[i + 1] == '#')
                return false;
        bool flag = false;
        for (int i = b; i <= d and i + 1 < n; i++)
            if (i - 1 >= 0)
                if (s[i] == '.' and s[i + 1] == '.' and s[i - 1] == '.')
                    flag = true;
        if (flag == false)
            return false;
    }
    return true;
}
int main() {
    cin >> n >> a >> b >> c >> d >> s;
    cout << (solve() ? "Yes" : "No") << endl;
}