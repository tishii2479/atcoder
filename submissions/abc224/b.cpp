#include <bits/stdc++.h>
using namespace std;

int h, w;
int a[51][51];
int main() {
    cin >> h >> w;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) cin >> a[i][j];

    bool ok = true;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            for (int k = i + 1; k < h; k++)
                for (int l = j + 1; l < w; l++) {
                    if (a[i][j] + a[k][l] > a[i][l] + a[k][j]) ok = false;
                }
    cout << (ok ? "Yes" : "No") << endl;
}
