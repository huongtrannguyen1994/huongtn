#include <bits/stdc++.h>

using namespace std;

int mX[4] = {1, -1, 0, 0};
int mY[4] = {0, 0, 1, -1};
int N, M;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    vector<vector<bool>> visit(N, vector<bool>(M, false));
    queue<pair<int,int>> q;
    pair<int,int> p = {sr, sc};
    int originC = image[sr][sc];
    q.push(p);
    visit[sr][sc] = true;
    image[sr][sc] = color;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        // cout << x << " " << y << endl;
        q.pop();
        // visit[x][y] = true;
        // image[x][y] = color;
        for(int i=0; i<4; ++i) {
            int X = x + mX[i];
            int Y = y + mY[i];
            if (X < 0 || X >= N || Y < 0 || Y >= M) continue;
            if(image[X][Y] == originC && !visit[X][Y]) {
                // cout << x << " " << y << endl;
                image[X][Y] = color;
                visit[X][Y] = true;
                pair<int,int> p1 = {X, Y};
                q.push(p1);
            }
        }
    }
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
    return image;
}

int main() {
    int sr, sc, co;
    vector<vector<int>> img = {{1,1,1},{1,1,0},{1,0,1}};
    N = img[0].size();
    M = img.size();
    // cout << N << " " << M << endl;
    sr = 1;
    sc = 1;
    co = 2;
    floodFill(img, sr, sc, co);
}