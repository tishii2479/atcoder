#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    string s, t;
    cin >> s >> t;
    int n = s.length();
    map<char, char> mp;
    map<char, char> mp2;
    for (int i = 0; i < 26; i++) {
        mp[(char)(i + 'a')] = ' ';
        mp2[(char)(i + 'a')] = ' ';
    }
    for (int i = 0; i < n; i++) {
        if (mp[s[i]] == t[i] and mp2[t[i]] == s[i])
            continue;
        if (mp[s[i]] != t[i] and mp[s[i]] != ' ') {
            cout << "No" << endl;
            return 0;
        }
        if (mp2[t[i]] != s[i] and mp2[t[i]] != ' ') {
            cout << "No" << endl;
            return 0;
        }
        if (mp[s[i]] == ' ')
            mp[s[i]] = t[i];
        if (mp2[t[i]] == ' ')
            mp2[t[i]] = s[i];
    }
    cout << "Yes" << endl;
}