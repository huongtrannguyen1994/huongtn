#include <bits/stdc++.h>

using namespace std;

int N,M;
vector<vector<string>> gird = {{"a","b","b"},{"b","z","b"},{"b","b","a"}};

int mX[4] = {1, -1, 0, 0};
int mY[4] = {0, 0, 1, -1};

bool ans = false;

bool check(int x, int y) {
    if (x >= 0 && x < M && y >= 0 && y < N) return true;
    return false;
}

bool bfs(int x, int y, int lastX, int lastY, vector<vector<string>>& grid, vector<vector<bool>>& visit) {
    visit[x][y] = true;

    for (int i = 0; i < 4; ++i) {
        int X = x + mX[i];
        int Y = y + mY[i];
        if (check(X, Y) && !(X == lastX && Y == lastY) && grid[x][y] == grid[X][Y]) {
            if (visit[X][Y] || bfs(X, Y, x, y, grid, visit)) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    N = gird[0].size();
    M = gird.size();
    vector<vector<bool>> visit(M, vector<bool>(N, false));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (visit[i][j] == false && bfs(i, j, -1, -1, gird, visit)) cout << true;
        }
    }
    cout << false;
    return 0;
}