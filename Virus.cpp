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

int N, M;
vector<int> A, B;
vector<vector<int>> virus;
vector<int> cfg;

bool findVirus(vector<int>& v) {
    int n = virus.size();
    int n1 = virus[0].size();
    for(int i = 0; i < n; ++i) {
        bool check1 = true;
        for (int j = 1; j < n1; ++j) {
            int first = v[j-1] - virus[i][j-1];
            int second = v[j] - virus[i][j];
            // debug(first, second);
            if(first != second) {
                check1 = false;
                break;
            }
        }
        if(check1 == true) return true;
    }
    return false;
}

void bt(int idx) {
    if(idx == M) {
        virus.push_back(cfg);
        return;
    }

    for(int i = 0; i < M; ++i) {
        bool canUse = true;
        for(auto x:cfg) {
            if(B[i] == x) {
                canUse = false;
                break;
            }
        }
        if(canUse) {
            cfg.push_back(B[i]);
            bt(idx+1);
            cfg.pop_back();
        }
    }
}

int main() {
    cin >> N >> M;

    A.resize(N,0);
    B.resize(M,0);

    for(auto& x:A) {
        cin >> x;
    }
    for(auto& x:B) {
        cin >> x;
    }
    // int i = 0;
    // do {
    //     // vector<int> temp;
    //     // for(auto x:B) {
    //     //     temp.push_back(x);
    //     // }
    //     virus.push_back(B);
    //     debug(B);
    //     // i++;
    // }while(next_permutation(B.begin(), B.begin()+M));
    bt(0);
    debug(virus);
    int c = 0;
    for(int i = 0; i <= N - M; ++i) {
        vector<int> t;
        for(int j = 0; j < M; ++j) {
            t.push_back(A[i+j]);
        }
        debug(t);
        if(findVirus(t) == true) {
            cout << "true" ; debug(t);
            c++;
        }
    }
    cout << c;

    return 0;
}

