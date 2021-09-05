#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    string s = "";

    while (n > 0) {
        if (n % 2 == 0) {
            n /= 2;
            s += "B";
        } else {
            n -= 1;
            s += "A";
        }
    }

    reverse(s.begin(), s.end());

    cout << s << endl;
}
