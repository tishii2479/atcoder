#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n;
    double x, y, x2, y2;
    cin >> n >> x >> y >> x2 >> y2;
    double cx = (x + x2) / 2, cy = (y + y2) / 2;
    double theta = 2.0 * M_PI / n;
    double x1 = cx + cos(theta) * (x - cx) - sin(theta) * (y - cy);
    double y1 = cy + sin(theta) * (x - cx) + cos(theta) * (y - cy);
    printf("%.10lf %.10lf\n", x1, y1);
}