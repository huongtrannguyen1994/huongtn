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

void caculator(int g, int& c0, int& c1) {
    if (g == 1) c1++;
    else c0++;
    // cout << g << " " << c0 << " " << c1 << endl;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> gird(n,vector<int>(n));
    vector<vector<int>> v(n,vector<int>(n, false));

    for(int i = 0; i < n; ++i) {
        string c;
        cin >> c;
        for(int j = 0; j < n; ++j) {
            gird[i][j] = c[j] - '0';
        }
    }
    int ans = 0;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if (v[i][j] == true) continue;
            int c_1 = 0, c_0 = 0;
            caculator(gird[i][j],c_0,c_1);
            v[i][j] = true;
            caculator(gird[j][n-i-1],c_0,c_1);
            v[j][n-i-1] = true;
            caculator(gird[n-i-1][n-1-j],c_0,c_1);
            v[n-i-1][n-1-j] = true;
            caculator(gird[n-1-j][i],c_0,c_1);
            v[n-1-j][i] = true;
            if(c_0 >= c_1) ans += c_1;
            else ans += c_0;
        }
    }

    cout << ans << endl;

}


int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    
    return 0;
}