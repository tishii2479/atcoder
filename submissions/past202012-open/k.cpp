#include <bits/stdc++.h>
using namespace std;

const int N = 4;

vector<string> s(N);
bool seen[1 << (N * N)];
double dp[1 << (N * N)];

int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {1, 0, -1, 0, 0};

//  0,  1,  2,  3
//  4,  5,  6,  7
//  8,  9, 10, 11
// 12, 13, 14, 15

int idx(int x, int y) {
    return y * N + x;
}

pair<int, int> p(int idx) {
    return {idx / N, idx % N};
}

double solve(int bit) {
    if (seen[bit]) return dp[bit];
    if (bit == 0) return 0;
    seen[bit] = true;
    dp[bit] = 1e50;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int cnt = 0;
            double sum = 0;

            for (int d = 0; d < 5; d++) {
                int ni = i + dy[d], nj = j + dx[d];
                if (ni < 0 or nj < 0 or ni >= N or nj >= N) continue;
                if (s[ni][nj] == '#' and (bit & (1 << idx(nj, ni)))) {
                    cnt++;
                    sum += solve(bit ^ (1 << idx(nj, ni)));
                }
            }
            if (cnt == 0) continue;
            dp[bit] = min(dp[bit], (double)5 / cnt * (sum / 5 + 1));
        }
    }
    return dp[bit];
}

int main() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> s[i][j];

    int first = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (s[i][j] == '#') first |= (1 << idx(j, i));
        }
    }

    cout << fixed << setprecision(10) << solve(first) << endl;
}
