#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#define MOD 1000000009
using namespace std;
typedef long long ll;
int main() {
    string s;
    cin >> s;
    if (s[s.length() - 1] == 's') {
        cout << s << "es" << endl;
    } else {
        cout << s << "s" << endl;
    }
}