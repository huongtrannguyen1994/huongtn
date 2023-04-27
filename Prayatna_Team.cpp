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
 

void solve(int n, int m, vector<int>& a) {
    vector<vector<int>> gird(n+1, vector<int>());
    for(int i = 0; i < m; ++i) {
        int c, d;
        cin >> c >> d;
        gird[c].push_back(d);
        gird[d].push_back(c);
    }

    vector<bool> v(n+1, false);
    stack<int> s;
    int ans = 0;
    int minL;
    // debug(a);
    // debug(gird);
    for(int j = 1; j <= n; ++j){
        // arr.clear();
        if(v[j] != true) {
            s.push(j);
            minL = a[j];
            // debug(s);
            while(s.size() > 0) {
                int u = s.top();
                v[u] = true;
                s.pop();
                minL = min(minL, a[u]);
                for(auto y:gird[u]) {
                    if (v[y] == false) {
                        s.push(y);
                        v[y] = true;
                    }
                }
            }
            ans += minL;
        }
        // ans += minL;
        
        cout << "ans: " << ans << endl;
    }
    // for(int i = 1; i <= n; ++i) {
    //     if(v[i] != true) {
    //         ans += a[i];
    //     }
    // }
    cout << ans;
}


int32_t main()
{
    int n, m;
    cin>>n >> m;
    vector<int> a(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    solve(n, m, a);
    // while(t--)
    // {
    //     solve(grid);
    // }
    
    return 0;
}