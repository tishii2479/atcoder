#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    multiset<int> st;
    deque<int> added;

    while (q--) {
        int c;
        cin >> c;
        if (c == 1) {
            int x;
            cin >> x;
            added.push_back(x);
        } else if (c == 2) {
            if (st.size() > 0) {
                auto it = st.begin();
                cout << *it << endl;
                st.erase(it);
            } else {
                cout << added.front() << endl;
                added.pop_front();
            }
        } else {
            for (int e : added) st.insert(e);
            added.clear();
        }
    }
}
