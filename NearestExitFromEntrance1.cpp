#include <bits/stdc++.h>

using namespace std;

int N, M;
int ans = INT_MAX;
typedef pair<int,pair<int,int>> item;
#define for_n(i, n) for(int i=0; i<n; ++i)
int mX[4] = {1, -1, 0, 0};
int mY[4] = {0, 0, -1, 1};

void dfs(int x, int y, int cnt, int lastX, int lastY, vector<vector<string>>& maze, vector<vector<bool>> visit) {
    cout << "1: " << x << y << cnt << lastX << lastY << endl;
    if(x == 0 || y == 0 || x == M-1 || y == N-1) {
        if(cnt != 0) ans = min(cnt, ans);
        return;
    }
    visit[x][y] = true;
    for_n(i, 4) {
        int X = x + mX[i];
        int Y = y + mY[i];
        cout << "2: " << X << Y << endl;
        if (X < 0 || Y < 0 || X >= M || Y >= N) continue;
        if (!visit[X][Y] && !(X == lastX && Y == lastY) && maze[X][Y] == maze[x][y]) {
            cout << "3: " << X << Y << endl;
            dfs(X, Y, cnt+1, x, y, maze, visit);
        }
    }
}

int nearestExit(vector<vector<string>>& maze, vector<int>& entrance) {
    int x = entrance[0];
    int y = entrance[1];

    vector<vector<bool>> visit(M, vector<bool>(N, false));
    // priority_queue<item> dest;
    // for_n(i, N) {
    //     for_n(j, M) {
    //         pair<int,int> t = {i, j};
    //         dest.push({INT_MAX, t});
    //     }
    // }
    int idx = 0;


    dfs(x, y, idx, -1, -1, maze, visit);
    if(ans == INT_MAX) return -1;
    return ans;
}

int main() {
    vector<vector<string>> A = {{"+","+",".","+"},{".",".",".","+"},{"+","+","+","."}};
    vector<int> B = {1,2};

    N = A[0].size();
    M = A.size();
    cout << N << M << endl;
    cout << nearestExit(A, B);
    return 0;

}