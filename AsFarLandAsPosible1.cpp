#include <bits/stdc++.h>

using namespace std;

int maxDistance(vector<vector<int>>& grid) {
    cout <<"1";
    int n = grid.size();
    int mX[4] = {1, -1, 0, 0};
    int mY[4] = {0, 0, -1, 1};
    vector<vector<int>> dist(n, vector<int>(n, 0));
    vector<vector<bool>> visit(n, vector<bool>(n, false));
    queue<array<int, 2>> q;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            if(grid[i][j] == 1) {
                cout <<"2";
                q.push({i,j});
                visit[i][j] = true;
            }
        }
    }

    int ans = -1;
    cout <<"2.1";
    while(!q.empty()) {
        cout <<"3";
        auto [r, c] = q.front();
        q.pop();
        for(int i=0; i<4; ++i) {
            int X = r + mX[i];
            int Y = c + mY[i];
            if (X < 0 || X>=n || Y<0 || Y>=n) continue;
            if(!visit[X][Y]) {
                cout <<"4";
                q.push({X,Y});
                visit[X][Y] = true;
                dist[X][Y] = dist[r][c] + 1;
                cout << "dist[X][Y]: " << dist[X][Y] << " " << X << Y << endl;
                ans = max(ans, dist[X][Y]);
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> grid = {{1,0,1}, {0,0,0}, {1,0,1}};
    cout << maxDistance(grid);
    return 0;
}