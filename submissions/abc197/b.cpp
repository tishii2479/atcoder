#include <bits/stdc++.h>
using namespace std;
using ll = long long;
pair<int, int> unit[4] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};
int main() {
    int h, w, x, y;
    cin >> h >> w >> y >> x;
    string s[110];
    for (int i = 0; i < h; i++)
        cin >> s[i];
    int cnt = 0;
    x--, y--;
    for (int i = 0; i < 4; i++) {
        for (int j = 1;; j++) {
            int nx = x + unit[i].first * j;
            int ny = y + unit[i].second * j;
            if (nx < 0 or ny < 0 or nx >= w or ny >= h)
                break;
            if (s[ny][nx] == '#')
                break;
            cnt++;
        }
    }
    cout << cnt + 1 << endl;
}