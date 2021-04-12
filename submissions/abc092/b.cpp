#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int a, b;
    cin >> a >> b;
    int h = 100;
    int w = 100;
    cout << h << " " << w << endl;
    char field[100][100];
    bool flag = false;
    if (a > b) {
        swap(a, b);
        flag = true;
    }
    // a < b
    a--;
    int tmpa = a;
    for (int i = 0; i < w; i++) {
        if (a > 0) {
            for (int j = 0; j < h; j++) {
                if (i % 2 == 0) {
                    if (j % 2 == 0 and a > 0) {
                        field[j][i] = '.';
                        a--;
                    } else
                        field[j][i] = '#';
                } else {
                    if (j % 2 == 1 and a > 0) {
                        field[j][i] = '.';
                        a--;
                    } else
                        field[j][i] = '#';
                }
            }
        } else {
            break;
        }
    }
    int bnow = max(0, tmpa - 50);
    int xnow = (tmpa + 49) / 50;
    for (int i = 0; i < h; i++)
        field[i][xnow] = '#';
    for (int i = xnow + 1; i < w; i++)
        for (int j = 0; j < h; j++)
            field[j][i] = '.';
    int left = b - bnow - 1;
    for (int i = xnow + 2; i < w; i += 2)
        for (int j = 0; j < h; j += 2) {
            left--;
            if (left < 0)
                break;
            field[j][i] = '#';
        }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (flag) {
                if (field[i][j] == '#')
                    cout << ".";
                else
                    cout << "#";
            } else {
                cout << field[i][j];
            }
        }
        cout << endl;
    }
}