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

#define for_n(i, n) for(int i = 0; i < n; ++i)
// #define R 1
// #define G 2
// #define B 3

int N;
int mX[4] = {1, -1, 0, 0};
int mY[4] = {0, 0, 1, -1};

struct Product {
    int id;
    int countAllItem;
    int maxItem;
    int island;
    bool operator < (const Product& that) {
        if(that.countAllItem == countAllItem) {
            return that.maxItem < maxItem;
        }
        return that.countAllItem < countAllItem;
    }
};

void Solve(vector<vector<int>>& H, int x, int y, Product& P) {
    int colorF = H[x][y];
    queue<pair<int,int>> q;
    pair<int,int> p = {x,y};
    q.push(p);
    H[x][y] = 0;
    int c = 1;
    P.countAllItem += 1;
    P.island += 1;
    while(!q.empty()) {
        int x1 = q.front().first;
        int y1 = q.front().second;
        q.pop();

        for_n(i, 4) {
            int X = x1 + mX[i];
            int Y = y1 + mY[i];
            if(X < 0 || X >= N || Y < 0 || Y >= N) continue;
            if(H[X][Y] == colorF){
                H[X][Y] = 0;
                debug(X);
                debug(Y);
                pair<int,int> p1 = {X,Y};
                q.push(p1);
                P.countAllItem += 1;
                c += 1;
            }
        }
    }
    debug(P.countAllItem);
    debug(c);
    debug(P.maxItem);
    debug(H);
    if(c > P.maxItem) P.maxItem = c;
}

int main() {
    cin >> N;
    vector<vector<int>> H(N,vector<int>(N,0));

    for_n(i, N){
        string s;
        cin >> s;
        for_n(j, N){
            if(s[j] == 'R') H[i][j] = 1;
            else if(s[j] == 'B') H[i][j] = 2;
            else if(s[j] == 'G') H[i][j] = 3;
        }
    }
    vector<Product> P(3);
    debug(H);
    for(int i = 1; i < 4; ++i){
        P[i-1].id = i;
        debug(P[i-1].id);
    }
    for_n(i, N){
        for_n(j, N) {
            for(int h = 0; h < 3; ++h){
                if( P[h].id == H[i][j]) {
                    debug(P[h].id);
                    debug(H[i][j]);
                    Solve(H, i, j, P[h]);
                }
            }
        }
    }
    debug(H);
    sort(P.begin(), P.end());
    // debug(P);
    for(int i = 0; i < 3; ++i){
        debug(P[i].id);
        debug(P[i].countAllItem);
        debug(P[i].maxItem);
        // debug(P[i].island);
    }
    if(P[0].id == 1) cout << "R";
    else if(P[0].id == 2) cout << "B";
    else if(P[0].id == 3) cout << "G";
    cout << " " << P[0].island;
    return 0;
}