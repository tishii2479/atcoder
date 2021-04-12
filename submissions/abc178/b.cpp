#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#define MOD 1000000009
using namespace std;
typedef long long ll;
int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << max(a * c, max(a * d, max(b * c, b * d))) << endl;
}