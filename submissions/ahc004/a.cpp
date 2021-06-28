#include <bits/stdc++.h>
using namespace std;
#include <sys/time.h>

using Mat = vector<vector<char>>;
const int N = 20;

void print_mat(Mat mat) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cout << mat[i][j];
        cout << endl;
    }
}

pair<int, int> unit[4] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}};

bool exist(string s, Mat mat) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            bool ok = true;
            for (int k = 0; k < s.length() and ok; k++) {
                int nx = j + unit[i].first * k, ny = i + unit[i].second * k;
                if (s[k] != mat[((ny % N) + N) % N][((nx % N) + N) % N]) ok = false;
            }
            if (ok) return true;
        }
    }
    return false;
}

int get_rand(int min, int max) {
    assert(min <= max);
    return min + rand() % (max - min);
}

int main() {
    time_t start = clock();
    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand((unsigned int)tv.tv_sec * ((unsigned int)tv.tv_usec + 1));
    int n, m;
    cin >> n >> m;
    vector<string> s(m);
    for (int i = 0; i < m; i++) cin >> s[i];

    sort(s.begin(), s.end(), [](string a, string b) {
        return a.length() > b.length();
    });

    Mat mat(N, vector<char>(N, '.'));
    int cnt = 0;

    for (int i = 0; i < m; i++) {
        if (exist(s[i], mat)) continue;
        int start = cnt % N;
        int dx = 0;
        while (dx < N and mat[start][dx] != '.') dx++;

        for (int j = 0; j < s[i].length(); j++) {
            mat[start][((j + dx) % N + N) % N] = s[i][j];
        }
        cnt++;
    }

    print_mat(mat);
}
