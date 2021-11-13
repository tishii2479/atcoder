#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<string> v;
    const int n = s.length();
    for (int i = 0; i < n; i++) {
        string t = "";
        for (int j = 1; j < n; j++) {
            t += s[j];
        }
        t += s[0];
        s = t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());

    cout << v[0] << endl
         << v[n - 1] << endl;
}
