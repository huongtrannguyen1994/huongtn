
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


int main() {
    int N;
    cin >> N;
    vector<int> M(N+1,0);
    for(int i = 1; i <= N; ++i) {
        cin >> M[i];
    }
    int tot = 0;
    vector<int> A(N+1,0); // độ cao lớn nhất tại vị trí i của A[i] + P[i]
    vector<int> B(N+1,0); // độ cao lớn nhất tại vị trí i của A[i] - P[i]
    // debug(ans);
    for(int i = 1; i <= N; ++i) {
        A[i] = max(A[i-1], B[i-1] + M[i]);
        B[i] = max(B[i-1], A[i-1] - M[i]);
        tot = max(A[i], B[i]);
    }
    cout << tot;
    return 0;
}
// A[i] // độ cao lớn nhất tại vị trí i của A[i] + P[i]
// B[i] // độ cao lớn nhất tại vị trí i của A[i] - P[i]

// A[0] = B[0] = 0;

// for(int i = 1; i<= n; ++i) {
//     A[i] = max(A[i-1], B[i-1] + P[i]);
//     B[i] = max(B[i-1], A[i-1] - P[i]);
// }
// ans = max(A[i], B[i]);