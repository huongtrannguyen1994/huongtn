#include <bits/stdc++.h>

using namespace std;

int N, M;
typedef pair<int,int> item;
int mX[4] = {1, -1, 0, 0};
int mY[4] = {0, 0, -1, 1};

vector<int> result;

int maxDistance(vector<vector<int>>& grid) {
    vector<vector<bool>> visit(N, vector<bool>(N, false));
    int N, M;
    typedef pair<int,int> item;
    N = grid.size();
    int mX[4] = {1, -1, 0, 0};
    int mY[4] = {0, 0, -1, 1};

    queue<pair<int, item>> q;

    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            if (grid[i][j] == 0) {
                // cout << "1: " << i << j << endl;
                int ans = INT_MAX;
                vector<vector<bool>> visit(N, vector<bool>(N, false));
                q.push({0, {i,j}});
                while(!q.empty()) {
                    
                    int x = q.front().second.first;
                    int y = q.front().second.second;
                    int cnt = q.front().first;
                    q.pop();
                    visit[x][y] = true;
                    // cout << "2: " << x << y << endl;
                    for(int u = 0; u < 4; u++) {
                        int X = x + mX[u];
                        int Y = y + mY[u];
                        // cout << "3: " << X << Y << endl;
                        if (X < 0 || X >=N || Y < 0 || Y >= N) continue;
                        if(grid[X][Y] == 1) {
                            cnt++;
                            ans = min(cnt, ans);
                            // cout << "4: " << X << Y << " " << ans << endl;
                        } else if (!visit[X][Y]) {
                            q.push({cnt+1, {X,Y}});
                            // cout << "5" << endl;
                        }
                
                    }
                }
                if(ans != INT_MAX) result.push_back(ans);
            }
        }
    }
    // for(auto x:result) cout << x <<" ";
    if(result.size() == 0) return -1;
    sort(result.begin(), result.end());
    return result[result.size()-1];
}

int main() {
    vector<vector<int>> grid = {{1,0,1}, {0,0,0}, {1,0,1}};
    cout << maxDistance(grid);
    return 0;
}