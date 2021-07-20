#include <bits/stdc++.h>
using namespace std;

struct Vector3 {
    long double x, y, z;
};

long double distance(Vector3 a, Vector3 b) {
    long double dx = a.x - b.x;
    long double dy = a.y - b.y;
    long double dz = a.z - b.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

int main() {
    long double x, y, l, t;
    int q;
    cin >> t >> l >> x >> y >> q;
    Vector3 statue = {x, y, 0};
    while (q--) {
        int e;
        cin >> e;
        long double rad = (long double)e / t * 2 * M_PI;
        long double y = -sinl(rad) * l / 2;
        long double z = -cosl(rad) * l / 2 + l / 2;
        Vector3 pos = {0, y, z};
        long double dist = distance(statue, pos);
        long double height = z;
        cout << fixed << setprecision(15) << asinl(height / dist) / 2 / M_PI * 360 << endl;
    }
}
