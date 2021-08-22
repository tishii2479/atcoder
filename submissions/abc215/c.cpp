#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    const int n = s.length();

    set<string> all;
    vector<int> v(n);

    for (int i = 0; i < n; i++) v[i] = i;

    do {
        string t = "";
        for (int i = 0; i < n; i++) t += s[v[i]];

        all.insert(t);
    } while (next_permutation(v.begin(), v.end()));

    auto it = all.begin();
    for (int i = 0; i < k - 1; i++) it++;
    cout << *it << endl;
}
