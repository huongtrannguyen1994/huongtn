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

int N;//Number of buildings
vector<int> H;//Height of buildings
long long ans = 0;

// void Input_Data(void){
// 	cin >> N;
// 	H.resize(N);
// 	for (int i = 0; i < N; i++){
// 		cin >> H[i];
// 	}
// }
void clearStack(stack<int>& s) {
    while(!s.empty()) {
        s.pop();
    }
}

void cleartoMaxStack(stack<int>& s, int h) {
    cout << "6";
    while(!s.empty()) {
        cout << "7";
        if(h > s.top()) ans += 1;
        if(h >= s.top()) {
            s.pop();
        } else {
            return;
        }
    }
    cout << "8";
}

void caculator() {
	
    vector<int> next_right(N+1, N);
    stack<int> s;
    int max = H[0];
    int max_stack = 0;
	for(int i = 0; i < N; ++i) {
        if(!s.empty()) {
            cout << "1";
            int tem = s.top();
            cout << "2";
            if(H[i] > tem) {
                cout << "5";
                // ans += s.size();
                cleartoMaxStack(s, H[i]);
                s.push(H[i]);
            } else if(H[i] < tem){
                s.push(H[i]);
            } 
            cout << "3";
            if(H[i] > max_stack) max_stack = H[i];
            cout << "4";
            if(H[i] >= max) {
                clearStack(s);
                // s.push(H[i]);
                max = H[i];
                max_stack = 0;
            }
            debug(H[i]);
            debug(max_stack);
            debug(max);
            debug(s);
            debug(ans); 

        //     }
        } else {
            // max = H[i];
            if(H[i] < max) {
                s.push(H[i]);
            } else {
                max = H[i];
            }
            // s.push(H[i]);
        }
        // } else {
        //     // max = H[i];
        //     s.push(H[i]);
        // }
    }
	cout << ans;
}

int main(){
	// long long ans = -1;
    cin >> N;
	H.resize(N);
	for (auto& x:H){
		cin >> x;
	}
    H.push_back(INT_MAX);
	caculator();
	return 0;
}
