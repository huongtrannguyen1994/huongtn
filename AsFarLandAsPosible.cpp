#include <bits/stdc++.h>

using namespace std;

int N, M;
typedef pair<int,int> item;
int mX[4] = {1, -1, 0, 0};
int mY[4] = {0, 0, -1, 1};

int ans = 0;

int maxDistance(vector<vector<int>>& grid) {
    vector<vector<bool>> visit(N, vector<bool>(N, false));

    queue<pair<int, item>> q;

    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            if (grid[i][j] == 0) {
                vector<vector<bool>> visit(N, vector<bool>(N, false));
                q.push({0, {i,j}});
                while(!q.empty()) {
                    int x = q.front().second.first;
                    int y = q.front().second.second;
                    int cnt = q.front().first;
                    q.pop();
                    visit[x][y] = true;
                    for(int u = 0; u < 4; u++) {
                    int x = u + mX[i];
                    int y = u + mY[i];
                    if (x < 0 || x >=N || y < 0 || y >= 0) continue;
                    if(grid[i][j] == 1) {
                        cnt++;
                        ans = max(cnt, ans);
                    }
                }
                }
                int check = false;
                for(int u = 0; u < 4; u++) {
                    int x = u + mX[i];
                    int y = u + mY[i];
                    if (x < 0 || x >=N || y < 0 || y >= 0) continue;
                    if(grid[i][j] == 1) {

                    }
                }
            }
        }
    }
    q.push({{0,0},{-1,-1}})
}

int main() {
    vector<vector<int>> grid = {{1,0,1}, {0,0,0}, {1,0,1}};
    N = grid.size();
    cout << maxDistance(grid);
    return 0;
}