#include <bits/stdc++.h>

using namespace std;

int N,M;
int mX[4] = {1, -1, 0, 0};
int mY[4] = {0, 0, -1, 1};
int minSteps = INT_MAX;
int co = 0;

typedef pair<int,pair<int,int>> pi;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

stack<vector<pair<int,int>>> s;

bool check(int x, int y) {
    if (x < 0 || x >= M || y < 0 || y >= N) return false;
    return true;
}
int dfs(int x, int y, int lastX, int lastY, vector<vector<bool>>& visit, vector<vector<string>>& maze) {
    visit[x][y] = true;
    cout << " 1 " << endl;
    for (int i=0; i<4; ++i) {
        int X = x + mX[i];
        int Y = y + mY[i];
        cout << " 2 ";
        cout << X << Y;
        cout << endl;
        if (check(X, Y) && maze[x][y] == maze[X][Y] && !(X == lastX && Y == lastY) && !visit[X][Y]){
            cout << " 3 " ;
            cout << X << Y;
            cout << endl;
            visit[X][Y] = true;
            co++;
            if(X == 0 || Y == 0 || Y == N-1 || X == M-1) {
                minSteps = min(minSteps, co);
                cout << " 4 co: " << co << " "<< endl;
                co--;
                continue;
            }
                cout << " 5 co: " << co << " "<< endl;
                
                dfs(X, Y, x, y, visit, maze);
                co--;
        }
        visit[X][Y] = false;
    }
    visit[x][y] = false;
}
int main() {
    // vector<vector<string>> maze = {{"+",".","+","+","+","+","+"},{"+",".","+",".",".",".","+"},{"+",".","+",".","+",".","+"},{"+",".",".",".",".",".","+"},{"+","+","+","+",".","+","."}};
    vector<vector<string>> maze = {{"+","+","+"},{".",".","."},{"+","+","+"}};
    vector<int> entrance = {1,0};
    // int x = entrance[0];
    // int y = entrance[1];
    // N = maze[0].size();
    // M = maze.size();
    // vector<vector<bool>> visit(M, vector<bool>(N, false));
    // for(int i=0; i<M; ++i) {
    //     for(int j=0; j<N; ++j) {
            
    //     }
    // }
    // dfs(x, y, -1, -1, visit, maze);
    // cout << minSteps;
    int m=maze.size();
        int n=maze[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        dist[entrance[0]][entrance[1]]=0;
        maze[entrance[0]][entrance[1]]="+";
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        pq.push({dist[entrance[0]][entrance[1]],{entrance[0],entrance[1]}});
        while(!pq.empty())
        {
            int d=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            if((x==0 or x==m-1 or y==0 or y==n-1) and maze[x][y]!="+")
                cout <<  dist[x][y];
            pq.pop();
            for(int k=0;k<4;k++)
            {
                int newx=x+dx[k];
                int newy=y+dy[k];
                if(newx<0 or newy<0 or newx>=m or newy>=n or maze[newx][newy]=="+")
                    continue;
                if(dist[newx][newy]>dist[x][y]+1)
                {
                    dist[newx][newy]=1+dist[x][y];
                    pq.push({dist[newx][newy],{newx,newy}});
                    if((newx==0 or newx==m-1 or newy==0 or newy==n-1) and maze[newx][newy]!="+")
                     cout <<  dist[newx][newy];
                }
            }
        }
        cout <<  "-1";
    return 0;
}