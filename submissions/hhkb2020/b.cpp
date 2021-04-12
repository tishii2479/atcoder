#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    int h, w, count = 0;
    cin >> h >> w;
    vector<vector<char> > tiles(h, vector<char>(w));
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            char c;
            cin >> c;
            tiles[y][x] = c;
        }
    }
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w - 1; x++) {
            if (tiles[y][x] == '.' && tiles[y][x + 1] == '.')
                count++;
        }
    }
    for (int x = 0; x < w; x++) {
        for (int y = 0; y < h - 1; y++) {
            if (tiles[y][x] == '.' && tiles[y + 1][x] == '.')
                count++;
        }
    }
    cout << count << endl;
}