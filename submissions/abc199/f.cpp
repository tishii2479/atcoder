#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

using mint = modint1000000007;
using M = vector<vector<mint>>;

M operator*(M a, M b) {
    int N = a.size();
    M res = M(N, vector<mint>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return res;
}

M pow_matrix(M a, int n) {
    int N = a.size();
    if (n == 0) {
        M b = M(N, vector<mint>(N, 0));
        for (int i = 0; i < N; i++) b[i][i] = 1;
        return b;
    }
    if (n == 1) {
        return a;
    }
    M t = pow_matrix(a, n / 2);
    if (n % 2 == 0) {
        return t * t;
    } else {
        return t * t * a;
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> edges(n, vector<int>(n, 0));
    vector<int> cnt(n, 0);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        cnt[x]++;
        cnt[y]++;
        edges[x][y] = 1;
        edges[y][x] = 1;
    }

    M matrix = M(n, vector<mint>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                matrix[i][j] = mint(m - cnt[i]) / m + mint(cnt[i]) / m / 2;
            } else {
                if (edges[i][j]) {
                    matrix[i][j] = mint(1) / m / 2;
                } else {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    M res = pow_matrix(matrix, k);

    for (int i = 0; i < n; i++) {
        mint val = 0;
        for (int j = 0; j < n; j++) {
            val += res[i][j] * a[j];
        }
        cout << val.val() << endl;
    }
}
