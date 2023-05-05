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

int B;
string S, D;

// Xóa các số 0 vô nghĩa ở đầu.
void del_zero(vector<int>& a) 
{ 
    reverse(a.begin(), a.end()); 
	
    while (a.size() >= 2) 
        if (a.back() == 0) 
            a.pop_back();
        else 
            break;

    reverse(a.begin(), a.end());
}

// Nhân hai số lớn.
vector<int> operator * (vector<int>& a, vector<int>& b)
{
    // Đảo ngược hai số trước để tiện tính toán.
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
	
    // Resize trước mảng kết quả. Kết quả của tích có thể đạt tới số chữ số  
    // bằng tổng độ dài của hai số ban đầu cộng lại và cộng thêm 1.
    vector<int> c(a.size() + b.size() + 1);
    for (int i = 0; i < (int) a.size(); ++i)
        for (int j = 0; j < (int) b.size(); ++j)
        {
            c[i + j] += (a[i] * b[j]);
            c[i + j + 1] += (c[i + j] / B);
            c[i + j] %= B;
            // cout << "C1: "; debug(c);
        }

    // Xử lý nốt phần giá trị nhớ chưa được cộng hết.
    // Mảng c hiện tại đang là mảng kết quả bị đảo ngược.
    c.push_back(0);
    for (int i = 0; i < (int) c.size() - 1; ++i) 
    {
    	c[i + 1] += (c[i] / B);
    	c[i] %= B;
        // cout << "C2: "; debug(c);
    }

    // Đảo ngược mảng c và xóa các chữ số 0 vô nghĩa ở đầu, ta sẽ thu được tích a * b.
    reverse(c.begin(), c.end());
    del_zero(c);
	
    return c;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> B >> S >> D;
    
    int sigS = 1;
    int sigD = 1;
    if (S[0] == '-') {
        sigS = -1;
        S.erase(S.begin());
    }
    if (D[0] == '-') {
        sigD = -1;
        D.erase(D.begin());
    }
    if(S[0] == '0' || D[0] == '0') {
        cout << '0' << endl;
        continue;
    }
    int ls = S.length();
    int ld = D.length();
    vector<int> a(ls), b(ld);
    for(int i = 0; i < ls; ++i) {
        if(S[i] <= 57 ) {
            a[i] = S[i]-'0';
        } else {
            a[i] = S[i]-55;
        }
    }
    for(int i = 0; i < ld; ++i) {
        if(D[i] <= 57 ) {
            b[i] = D[i]-'0';
        } else {
            b[i] = D[i]-55;
        }
        // b[i] = D[i]-'0';
    }
    vector<int> c(ls+ld+1);
    // debug(a);
    // debug(b);
    c = a * b;
    // debug(c);
    int sig = sigD * sigS;
    if(sig != 1) cout << '-';
    for(auto x:c) {
        char ans;
        if(x < 10) ans = x + 48;
        else ans = x + 55;
        cout << ans;
    }
    cout << endl;
    }

    return 0;
}

