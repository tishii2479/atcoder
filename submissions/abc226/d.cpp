#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    set<long double> st;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            long double dy = y[i] - y[j], dx = x[i] - x[j];
            st.insert(atan2(dy, dx));
        }
    }

    cout << st.size() << endl;
}
