#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> cnt(5, 0);
    for (int i = 0; i < 3; i++) {
        int a, b;
        cin >> a >> b;
        cnt[a]++;
        cnt[b]++;
    }
    for (int i = 1; i <= 4; i++)
        if (cnt[i] > 2) {
            cout << "NO" << endl;
            return 0;
        }
    cout << "YES" << endl;
}