#include <bits/stdc++.h>
using namespace std;
int main() {
    const int N = 210000;
    vector<int> a(N), b(N);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int j = 0, bef = -1;
    for (int i = 0; i < n; i++) {
        if (bef != a[i])
            j = 0;
        if (a[i] == b[i]) {
            for (; j < n; j++) {
                if (a[j] != a[i] and b[j] != a[i]) {
                    swap(b[i], b[j]);
                    break;
                }
            }
            if (a[i] == b[i]) {
                cout << "No" << endl;
                return 0;
            }
        }
        bef = a[i];
    }
    cout << "Yes" << endl;
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << endl;
}