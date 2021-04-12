#include <bits/stdc++.h>

#include <string>
using namespace std;
int main() {
    int n;
    string ans;
    cin >> n;
    switch (n % 10) {
        case 0:
        case 1:
        case 6:
        case 8:
            ans = "pon";
            break;
        case 3:
            ans = "bon";
            break;
        default:
            ans = "hon";
            break;
    }
    cout << ans << endl;
}