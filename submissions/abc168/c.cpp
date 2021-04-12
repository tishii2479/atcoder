#include <bits/stdc++.h>

#include <cmath>
using namespace std;
int main() {
    int a, b, h, m;
    double ang;
    cin >> a >> b >> h >> m;
    ang = 2 * M_PI * ((m / 60.0 + h) / 12.0 - m / 60.0);
    printf("%.15f\n", sqrt(pow(a, 2) + pow(b, 2) - (2.0 * a * b * cos(ang))));
}