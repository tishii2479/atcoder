#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
int main() {
    using mint = modint1000000007;
    int n;
    string s;
    cin >> n >> s;
    vector<int> cnt(26, 1);
    for (int i = 0; i < n; i++)
        cnt[s[i] - 'a']++;
    mint ans = 1;
    for (int i = 0; i < 26; i++)
        ans *= cnt[i];
    cout << (ans - 1).val() << endl;
}