#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> st;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (st.find(a) == st.end())
            st.insert(a);
        else
            st.erase(a);
    }
    cout << st.size() << endl;
}
