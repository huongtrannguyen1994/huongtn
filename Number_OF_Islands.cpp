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
 

void solve(vector<vector<int>>& gird) {
    int r = gird.size();
    int c = gird[0].size();
    vector<vector<bool>> v(r, vector<bool>(c, false));
    queue <pair<int,int>> q;
    int count = 0;

    int mX[] = {1, -1, 0, 0};
    int mY[] = {0, 0, 1, -1};

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (gird[i][j] != 1) continue;
            if (v[i][j] == true) continue;
            q.push({i, j});
            v[i][j] = true;
            count++;
            while(!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i1 = 0; i1 < 4; ++i1) {
                    int xl = x + mX[i1];
                    int yl = y + mY[i1];

                    if(xl < 0 || xl >= r || yl < 0 || yl >= c) continue;
                    if(!v[xl][yl] && gird[xl][yl] == 1) {
                        v[xl][yl] = true;
                        q.push({xl, yl});
                        debug(q);
                    }
                }
            }
        }
    }
    cout << count;
}


int32_t main()
{
    int t;
    cin>>t;
    vector<vector<int>> grid = {
  {1, 1, 1, 1, 0},
  {1, 1, 0, 1, 0},
  {1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1}};
    while(t--)
    {
        solve(grid);
    }
    
    return 0;
}