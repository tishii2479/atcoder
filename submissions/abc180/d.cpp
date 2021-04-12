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
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    ll count = 0;
    while ((double)a * x <= 2e18 and a * x <= x + b and a * x < y) {
        x *= a;
        count++;
    }
    count += (y - x - 1) / b;
    cout << count << endl;
}