#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
int n, m;
vector<int> a, b;
int solve() {
    using mint = modint1000000007;
    mint ans = 1;
    int i = 0, j = 0;
    for (int x = n * m; x >= 1; --x) {
        mint tmp = 1;
        if (a[i] == x and b[j] == x) {
            tmp = 1;
            i++, j++;
        } else if (a[i] == x) {
            tmp = j;
            i++;
        } else if (b[j] == x) {
            tmp = i;
            j++;
        } else {
            tmp = i * j - (n * m - x);
            if (tmp.val() <= 0)
                return 0;
        }
        ans *= tmp;
    }
    return ans.val();
}
int main() {
    cin >> n >> m;
    a.resize(n + 1, 0), b.resize(m + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    cout << solve() << endl;
}