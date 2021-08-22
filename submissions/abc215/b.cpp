#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long cur = 1;
    int k = 0;

    while (cur <= n) {
        cur *= 2;
        k++;
    }

    cout << k - 1 << endl;
}
