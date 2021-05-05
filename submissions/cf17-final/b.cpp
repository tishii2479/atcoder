#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> cnt(3, 0);

    for (int i = 0; i < s.length(); i++) cnt[s[i] - 'a']++;

    bool ok = true;

    for (int i = 0; i < 3; i++)
        for (int j = i + 1; j < 3; j++)
            if (abs(cnt[i] - cnt[j]) > 1) ok = false;

    cout << (ok ? "YES" : "NO") << endl;
}
