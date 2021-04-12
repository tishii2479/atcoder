#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n;
    cin >> n;
    set<string> s1;  // !==
    set<string> s2;  // ==
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s[0] == '!') {
            s1.insert(s);
        } else {
            s2.insert(s);
        }
    }
    for (string s : s2) {
        string ns = '!' + s;
        if (s1.find(ns) != s1.end()) {
            cout << s << endl;
            return 0;
        }
    }
    cout << "satisfiable" << endl;
    return 0;
}