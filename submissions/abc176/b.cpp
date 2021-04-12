#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int main() {
    string s;
    cin >> s;
    int mod = 9;
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        sum += (s[i] - '0') % mod;
    }
    if (sum % mod == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}