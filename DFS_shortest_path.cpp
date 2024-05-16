/* Shortest Path in a Grid with Obstacles Elimination
https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/description/
*/

#include <bits/stdc++.h>
using namespace std;

/******** Debug Code *******/
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename A>
void __print(const A &x);
template <typename A, typename B>
void __print(const pair<A, B> &p);
template <typename... A>
void __print(const tuple<A...> &t);
template <typename T>
void __print(stack<T> s);
template <typename T>
void __print(queue<T> q);
template <typename T, typename... U>
void __print(priority_queue<T, U...> q);
template <typename A>
void __print(const A &x) {
    bool first = true;
    cerr << '{';
    for (const auto &i : x) {
        cerr << (first ? "" : ","), __print(i);
        first = false;
    }
    cerr << '}';
}
template <typename A, typename B>
void __print(const pair<A, B> &p) {
    cerr << '(';
    __print(p.first);
    cerr << ',';
    __print(p.second);
    cerr << ')';
}
template <typename... A>
void __print(const tuple<A...> &t) {
    bool first = true;
    cerr << '(';
    apply([&first](const auto &...args) { ((cerr << (first ? "" : ","), __print(args), first = false), ...); }, t);
    cerr << ')';
}
template <typename T>
void __print(stack<T> s) {
    vector<T> debugVector;
    while (!s.empty()) {
        T t = s.top();
        debugVector.push_back(t);
        s.pop();
    }
    reverse(debugVector.begin(), debugVector.end());
    __print(debugVector);
}
template <typename T>
void __print(queue<T> q) {
    vector<T> debugVector;
    while (!q.empty()) {
        T t = q.front();
        debugVector.push_back(t);
        q.pop();
    }
    __print(debugVector);
}
template <typename T, typename... U>
void __print(priority_queue<T, U...> q) {
    vector<T> debugVector;
    while (!q.empty()) {
        T t = q.top();
        debugVector.push_back(t);
        q.pop();
    }
    __print(debugVector);
}
void _print() { cerr << "]\n"; }
template <typename Head, typename... Tail>
void _print(const Head &H, const Tail &...T) {
    __print(H);
    if (sizeof...(T))
        cerr << ", ";
    _print(T...);
}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

int sizeX, sizeY, desX, desY;
int K, minSteps = 1e9;
int mX[4] = {1, -1, 0, 0};
int mY[4] = {0, 0, 1, -1};

// void chooseV(int& x, int& y,const vector<vector<bool>>& v,const vector<vector<pair<int,int>>>& cnt) {
//     int minCnt = cnt[x][y].second;
//     int minStep = cnt[x][y].first;
//     if(x = DesX && y == DesY) {
//         cout << "Tim thay" << endl;
//     }
//     for(int i=0; i<sizeX-1; i++) {
//         for(int j=0; j<sizeY-1; j++) {
//             if(v[i][j] && cnt[i][j].second <= K && cnt[i][j].first < minStep ) {
//                 x = i;
//                 y = j;
//                 minCnt = cnt[i][j].first;
//             }
//         }
//     }
// }

bool check(int x, int y) {
    if (x >= 0 && x < sizeX && y >= 0 && y < sizeY) return true;
    return false;
}

bool checkMinStep(int S, int Obs, int k) {
    // cout << S << Obs << k << endl;
    debug(S, Obs, k);
    if(Obs <= k) {
        minSteps = min(minSteps, S);
        return true;
    }
    return false;
}

int shortestPath(vector<vector<int>>& grid, int k) {
    sizeX = grid.size();
    sizeY = grid[0].size();
    desX = sizeX-1;
    desY = sizeY-1;
    vector<vector<bool>> visit(sizeX, vector<bool>(sizeY, false));
    queue<pair<pair<int,int>,pair<int,int>>> q; // X,Y,steps,obstacle, vector
    int visited[sizeX][sizeY][k+1];
    memset(visited, 0, sizeof(visited));
    // visited[1][1][1] = 1;
    // visited[1][1][0] = 1;
    // debug(visited);

    q.push({{0,0},{0,0}});
    debug(desX, desY);
    visited[0][0][0] = 1;
    visited[0][0][1] = 1;
    while(!q.empty()){
        debug(q);
        int x = q.front().first.first;
        int y = q.front().first.second;
        int Step = q.front().second.first;
        int Obs = q.front().second.second;
        debug(x);
        debug(y);
        // vector<vector<bool>> v = q.front().second;
        // cout << "while: " << x << y << Step << Obs << endl;
        debug( x, y, Step, Obs);
        q.pop();
        visit[x][y] = true;
        if(x == desX && y == desY) {
            if(checkMinStep(Step, Obs, k)) return Step;
        }
        if(Obs > k) continue;
        for(int i=0; i<4; i++) {
            int X = mX[i]+x;
            int Y = mY[i]+y;
            debug(X);
            debug(Y);
            if(X < 0 || X >= sizeX || Y < 0 || Y >= sizeY) continue;
            // if(visit[X][Y] == false) {
            if(grid[X][Y] == 1 && Obs < k && visited[X][Y][Obs-1] == 0) {
                q.push({{X, Y},{Step+1, Obs+1}});
                visited[X][Y][Obs-1] = 1;
            } else if (grid[X][Y] == 0 && visited[X][Y][Obs] == 0) {
                q.push({{X, Y},{Step+1, Obs}});
                visited[X][Y][Obs] = 0;
            }

        }
    }
    // if(bfs(0, 0, -1, -1, g, visit, 0, 0, k)) {
    //     hasMin = true;
    // }
    debug(minSteps);
    if(minSteps == 1e9) cout << -1;
    else cout << minSteps;
}

int main() {
    //input
    // vector<vector<int>> grid = {{0,0,0},{1,1,0},{0,0,0},{0,1,1},{0,0,0}};
    // vector<vector<int>> grid = {{0,1,1},{1,1,1},{1,0,0}};
    vector<vector<int>> grid = {{0,1,0,0,0,1,0,0},{0,1,0,1,0,1,0,1},{0,0,0,1,0,0,1,0}};
    int k = 1;
    K = k;
    cout << shortestPath(grid, k);
    return 0;
}

