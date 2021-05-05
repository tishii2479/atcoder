#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) cin >> a[i][j];

    set<int> ok_x;
    set<int> ok_y;
    for (int i = 0; i < h; i++) {
        bool ok = false;
        for (int j = 0; j < w; j++)
            if (a[i][j] == '#') ok = true;
        if (ok) ok_y.insert(i);
    }

    for (int j = 0; j < w; j++) {
        bool ok = false;
        for (int i = 0; i < h; i++)
            if (a[i][j] == '#') ok = true;
        if (ok) ok_x.insert(j);
    }

    for (int i = 0; i < h; i++) {
        bool did = false;
        for (int j = 0; j < w; j++) {
            if (ok_y.count(i) and ok_x.count(j)) {
                cout << a[i][j];
                did = true;
            }
        }
        if (did) cout << endl;
    }
}
