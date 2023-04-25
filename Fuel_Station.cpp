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
int n, d, f;
bool Com(pair<int, int>& a, pair<int, int>& b) {
    return a.first > b.first;
}
int test(vector<pair<int, int>>& a) {
    // vector<bool> v(n, false);
    vector<int> p;
    int u, c;
    //      fisrt second pos count
    queue<vector<int>> par;

    
    // a.erase(a.begin()+n);
    sort(a.begin(), a.end(), Com);

    //                first second pos count
    p = {a[0].first, a[0].second, 1, 0};
    par.push(p);
    // v[0] = true;
    while(!par.empty()) {
        p = par.front();
        par.pop();

        // int pos = lower_bound(a.begin(), a.end(), )
        debug(p);
        debug(par);
        for(int i = p[2]; i <= n; ++i) {
            debug(a[i].first);
            debug(a[i].second);
            if(p[1] >= p[0]) return p[3];
            // 25       15          10
            if(p[0] - a[i].first > p[1]) break;
            // 10       10          25
            if(p[1] + a[i].second >= p[0]) return p[3]+1;
                        // 15
            int first = a[i].first;
                         //   10        25     15           10 
            int second = a[i].second - p[0] + a[i].first + p[1];
            int thir = i+1;
            int four = p[3]+1;
            vector<int> p1 = {first, second, thir, four};
            par.push(p1);
        }
    }
    return -1;
    
}
int main() {
    // int t;
    // cin >> t;
    // while(t > 0) {
    //     test(1);
    //     t--;
    // }
    cin >> n;
    vector<pair<int, int>> a(n+1);
    for(auto& x:a) {
        cin >> x.first >> x.second;
    }
    cout << test(a);
    // reserve(a.begin)
    return 0;
}