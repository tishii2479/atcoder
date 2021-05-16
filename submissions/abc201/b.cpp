#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, string>> m(n);
    for (int i = 0; i < n; i++) {
        cin >> m[i].second >> m[i].first;
    }

    sort(m.begin(), m.end(), greater{});

    cout << m[1].second << endl;
}
