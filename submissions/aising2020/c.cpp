#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n;
    cin >> n;
    vector<int> cnt(11000, 0);
    for (int x = 1; x <= 110; x++)
        for (int y = 1; y <= 110; y++)
            for (int z = 1; z <= 110; z++) {
                int a = x * x + y * y + z * z + x * y + x * z + y * z;
                if (a < 11000)
                    cnt[a]++;
            }
    for (int i = 1; i <= n; i++)
        cout << cnt[i] << endl;
}