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

template <typename T>
void debug_v(vector<vector<T>> v) {
    int n = v.size();
    int m = v[0].size();
    cout << "{";
    for_n(i, n) {
        cout << "{";
        for_n(j, m) {
            cout << v[i][j] << ",";
        }
        cout << "}";
    }
    cout << "}" << endl;
}

vector<pair<int,int>> color_paint_group[10];

int main() {
    int N;
    cin >> N;
    vector<vector<int>> a(N, vector<int>(N));
    vector<string> b(N);
    for(auto& x:b) {
        cin >> x;
    }
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            a[i][j] = b[i][j] - '0';
            pair<int,int> tem = {i, j};
            color_paint_group[a[i][j]].push_back(tem);
        }
    }
    int ans = 0;
    vector<vector<int>> v(N, vector<int>(N,0));
    vector<bool> valid(10, true);
    // int n = 
    for(int i = 1; i < 10; ++i) {
        // debug(i);
        int min_row = N, min_col = N, max_col = -1, max_row = -1;
        if(color_paint_group[i].size() == 0) {
            valid[i] = false;
            continue;
        }
        for(auto x:color_paint_group[i]) {
            min_row = min(x.first, min_row);
            min_col = min(x.second, min_col);
            max_row = max(x.first, max_row);
            max_col = max(x.second, max_col);
        }
        bool check = true;
        for(int row = min_row; row <= max_row; ++row) {
            for(int col = min_col; col <= max_col; ++col) {
                // debug(v[row][col]);
                if (a[row][col] != i) {
                    // check = false;
                    // ans++;
                    // break;
                    valid[a[row][col]] = false;
                }
                // v[row][col] = 1;
            }
            // if(check == false) {
            //     // ans--;
            //     break;
            //     // ans--;
            // }
        }
        // debug_v(v);
        // debug(check);
        // if (check) ans++;
    }
    for(int i = 1; i < 10; ++i){
        if(valid[i]) ans++;
    }
    cout << ans;
    // debug(ans);
    // debug(b);
    // debug(color_paint_group);
    return 0;
}