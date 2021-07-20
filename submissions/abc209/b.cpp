#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (i % 2 == 1) a -= 1;
        sum += a;
    }
    if (x >= sum)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
