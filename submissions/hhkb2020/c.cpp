#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n;
    cin >> n;
    set<int> st;
    for (int i = 0; i <= 210000; i++) st.insert(i);
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        st.erase(p);
        cout << *st.begin() << endl;
    }
}