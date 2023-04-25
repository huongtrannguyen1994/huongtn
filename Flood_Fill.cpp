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

void test(int idx) {
    // int n;
    // cin >> n;
    vector<int> a = {1,2,6,4,3,4,5};
    // sort(a.begin(), a.end());
    int pos = lower_bound(a.begin(), a.begin()+5, 6) - a.begin();
    cout << pos;
    
}

void bfs(vector<vector<int>>& gird, int x, int y, int color) {
    int ans = 0;
    int mX[] = {0, 0, 1, -1};
    int mY[] = {1, -1, 0, 0};
    queue <pair<int, int>> q;
    vector<vector<bool>> visit(gird.size(), vector<bool>(gird[0].size(), false));
    debug(visit);
    // for (int i = 0; i < gird.size(); ++i) {
    //     for (int j = 0; j < gird[0].size(); ++j) {
            // if (gird[i][j] != 1) continue;
            q.push({x, y});
            visit[x][y] = true;
            int originalColor = gird[x][y];
            gird[x][y] = color;

            while (!q.empty()) {
                int xl = q.front().first;
                int yl = q.front().second;
                q.pop();

                for (int i=0; i < 4; ++i) {
                    int u = xl + mX[i];
                    int v = yl + mY[i];

                    if (u >= gird.size() || u < 0) continue;
                    if (v >= gird[0].size() || v < 0) continue;
                    // if (gird[u][v] != 1) continue;

                    if (!visit[u][v] && gird[u][v] == originalColor) {
                        visit[u][v] = true;
                        gird[u][v] = color;
                        q.push({u, v});
                    }
                }
            }
            // ans++;
        // }
    // }
    debug(gird);
}

int main() {
   vector<vector<int>> gird {
    {1, 1, 1, 1, 0, 1},
    {1, 1, 1, 0, 1, 0},
    {1, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1}
   } ;
   debug(gird);
   bfs(gird, 1, 1, 3);
   cout << "Test";
   return 0;
}