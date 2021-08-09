#include <bits/stdc++.h>
using namespace std;

char s[10][10], t[10][10];

int main() {
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) s[i][j] = t[i][j] = '@';
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> s[i][j];
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> t[i][j];
        }
    }

    int need = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (t[i][j] == '#') need++;

    for (int d = 0; d < 4; d++) {
        for (int dy = -15; dy < 15; dy++) {
            for (int dx = -15; dx < 15; dx++) {
                bool ok = true;

                int cnt = 0;
                for (int i = 0; i < 10 and ok; i++) {
                    for (int j = 0; j < 10 and ok; j++) {
                        if (t[i][j] != '#') continue;
                        int y = dy + i, x = dx + j;
                        if (x < 0 or y < 0 or x >= 10 or y >= 10) {
                            ok = false;
                            break;
                        }
                        if (s[y][x] != '.') {
                            ok = false;
                            break;
                        }
                        cnt++;
                    }
                }

                if (ok and cnt == need) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }

        // rotate();
        char new_s[10][10];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                new_s[j][10 - i - 1] = s[i][j];
            }
        }

        swap(new_s, s);
        swap(h, w);
    }

    cout << "No" << endl;
}
