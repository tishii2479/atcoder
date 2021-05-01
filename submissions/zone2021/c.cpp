#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> data(5, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> data[j][i];
        }
    }

    int l = 0, r = 1e9 + 1;
    while (r - l > 1) {
        int x = (r + l) / 2;
        bool ok = false;
        set<int> st;
        for (int i = 0; i < n; i++) {
            int val = 0;
            for (int j = 0; j < 5; j++) {
                if (data[j][i] >= x) val |= (1 << j);
            }
            st.insert(val);
        }

        for (auto a : st)
            for (auto b : st)
                for (auto c : st)
                    if ((a | b | c) == ((1 << 5) - 1)) ok = true;

        if (ok)
            l = x;
        else
            r = x;
    }

    cout << l << endl;
}
