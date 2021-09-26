#include <bits/stdc++.h>
using namespace std;

int main() {
    string x;
    int n;
    cin >> x >> n;
    map<char, char> mp;
    for (int i = 0; i < 26; i++) {
        // mp[char('a' + i)] = x[i];
        mp[x[i]] = char('a' + i);
    }

    vector<string> s(n);
    vector<pair<string, int>> new_s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        new_s[i].second = i;
        for (int j = 0; j < s[i].length(); j++) {
            new_s[i].first += mp[s[i][j]];
        }
    }

    sort(new_s.begin(), new_s.end());

    for (int i = 0; i < n; i++) {
        cout << s[new_s[i].second] << endl;
    }
}
