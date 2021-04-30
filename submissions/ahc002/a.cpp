#include <bits/stdc++.h>
using namespace std;

#define DEBUG 0
#define TEST 0

const int N = 50;
int start_y, start_x;
int t[N][N], p[N][N];
int used[N][N];
bool tmp[N][N];
vector<char> path;
vector<char> ans;
pair<int, int> unit[4] = {
    {0, 1},
    {0, -1},
    {-1, 0},
    {1, 0}};
char dir[4] = {'R', 'L', 'U', 'D'};
int score = 0;
int current_score = -1;

void input() {
    cin >> start_y >> start_x;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> t[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> p[i][j];
}

bool is_able(int x, int y) {
    if (used[y][x]) return false;
    return true;
}

bool is_valid(int x, int y) {
    if (x < 0 or y < 0 or x >= N or y >= N) return false;
    return true;
}

bool is_same_tile(int x1, int y1, int x2, int y2) {
    if (t[y1][x1] == t[y2][x2]) return true;
    return false;
}

int get_random(int min, int max) {
    return rand() % (max - min) + min;
}

vector<int> find_space(int x, int y) {
    vector<int> res;
    set<int> remain = {0, 1, 2, 3};

    vector<pair<int, int>> v;
    const int span = 3;

    for (int i = 0; i < 4; i++) {
        int cnt = 0;
        int cy = y + unit[i].first * (span + 1), cx = x + unit[i].second * (span + 1);

        for (int i = -span; i <= span; i++) {
            for (int j = -span; j <= span; j++) {
                int py = cy + i, px = cx + j;
                if (is_valid(px, py) == false) continue;
                if (used[py][px] == false) cnt += (1 << ((abs(i) * abs(j)) / span));
            }
        }

        cnt *= get_random(20, 40);
        v.push_back({cnt, i});
    }

    sort(v.rbegin(), v.rend());
    for (int i = 0; i < 4; i++) res.push_back(v[i].second);

    return res;
}

void mark_used(int x, int y) {
    used[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int ny = y + unit[i].first, nx = x + unit[i].second;
        if (is_valid(nx, ny) == false) continue;
        if (is_same_tile(x, y, nx, ny)) used[ny][nx] = true;
    }
}

void attempt() {
    path.clear();
    score = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) used[i][j] = false;

    int y = start_y, x = start_x;
    bool moved = true;

    mark_used(x, y);

    while (moved) {
        moved = false;
        auto direction = find_space(x, y);
        for (int i : direction) {
            int ny = y + unit[i].first, nx = x + unit[i].second;
            if (is_valid(nx, ny) == false) continue;
            if (is_able(nx, ny)) {
                y = ny, x = nx;
                mark_used(x, y);
                path.push_back(dir[i]);
                moved = true;
                score += p[ny][nx];
                break;
            }
        }
    }
}

void solve() {
    clock_t start = clock();
    while ((double)(clock() - start) / CLOCKS_PER_SEC < 1.92) {
        attempt();
        if (score > current_score) {
            ans = path;
            current_score = score;
        }
        if (DEBUG) {
            cout << "Score: " << score << endl;
        }
    }
}

void output() {
    for (char p : ans) cout << p;
    cout << endl;
}

int main() {
    srand(24);
    input();
    solve();

    output();
    if (TEST) cout << current_score << endl;
    if (DEBUG) cout << "Score: " << current_score << endl;
}
