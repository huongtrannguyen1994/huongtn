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
//Binary_search
// vector<int> a = {1,2,6,4,3,4,5};
//     sort(a.begin(), a.end());
//     if (binary_search(a.begin(), a.end(), 3)) {
//         cout << "tim thay 3";
//     } else {
//         cout << "khong tim thay";
//     }

// Lower_bound search
// int a[] = {10, 20, 30, 40, 50, 40, 30, 20, 10};
// vector < int > v(a, a + 9);

// // a = {10, 10, 20, 20, 30, 30, 40, 40, 50}
// sort(a, a + 9);

// // Tìm vị trí của phần tử đầu tiên lớn hơn hoặc bằng 30 trong mảng a.
// // Muốn đưa ra vị trí là số nguyên thì lấy kết quả hàm trừ đi iterator a[0].
// int pos1 = lower_bound(a, a + 9, 30) - a;
// cout << "Vị trí đầu tiên lớn hơn hoặc bằng 30 là: " << pos1 << endl;

// // v = {50, 40, 40, 30, 30, 20, 20, 10, 10};
// sort(v.begin(), v.end(), comp);

// // Tìm vị trí đầu tiên nhỏ hơn hoặc bằng số 20 trong đoạn [0, 5] của vector v.
// // Tương tự, lấy hai iterator trừ cho nhau để ra được vị trí là số nguyên.
// int pos2 = lower_bound(v.begin(), v.begin() + 5, 20, comp) - v.begin();
// cout << "Vị trí đầu tiên nhỏ hơn hoặc bằng 20 là: " << pos2;

// upper_bound
// // Dạng 1:
// upper_bound(l, r, val);

// // Dạng 2:
// upper_bound(l, r, val, comp);
// int a[] = {10, 20, 30, 40, 50, 40, 30, 20, 10};
//     vector < int > v(a, a + 9);
	
//     // a = {10, 10, 20, 20, 30, 30, 40, 40, 50}
//     sort(a, a + 9);
	
//     // Tìm vị trí của phần tử đầu tiên lớn hơn 30 trong mảng a.
//     // Muốn đưa ra vị trí là số nguyên thì lấy kết quả hàm trừ đi iterator a[0].
//     int pos1 = upper_bound(a, a + 9, 30) - a;
//     cout << "Vị trí đầu tiên lớn hơn 30 là: " << pos1 << endl;

//     // v = {50, 40, 40, 30, 30, 20, 20, 10, 10};
//     sort(v.begin(), v.end(), comp);
    
//     // Tìm vị trí đầu tiên nhỏ hơn hơn 50 trong đoạn [0, 5] của vector v.
//     // Tương tự, lấy hai iterator trừ cho nhau để ra được vị trí là số nguyên.
//     int pos2 = upper_bound(v.begin(), v.end(), 50, comp) - v.begin();
//     cout << "Vị trí đầu tiên nhỏ hơn 50 là: " << pos2;

// equal_range
// int a[] = {10, 20, 30, 30, 20, 10, 10, 20};
//     // Biến tìm kiếm đối với mảng phải sử dụng con trỏ.
//     pair < int* , int* > bounds_1;
    
//     vector < int > v(a, a + 8);
//     // Biến tìm kiếm đối với vector phải sử dụng iterator.
//     pair < vector < int > :: iterator, vector < int > :: iterator > bounds_2;

//     // a = {10, 10, 10, 20, 20, 20, 30, 30}.
//     sort(a, a + 8);

//     // Dùng phép toán so sánh mặc định với mảng a.
//     // Tìm kiếm đoạn đầu tiên bằng 20.
//     bounds_1 = equal_range(a, a + 8, 20); // Đoạn [3, 6].
//     cout << bounds_1.first - a << ' ' << bounds_1.second - a << endl;

//     // v = {30, 30, 20, 20, 20, 10, 10, 10}.
//     sort(v.begin(), v.end(), comp);

//     // Dùng phép toán so sánh comp với vector v.
//     // Iterator first: Trỏ vào phần tử đầu tiên nhỏ hơn hoặc bằng 20.
//     // Iterator second: Trỏ vào phần tử đầu tiên nhỏ hơn 20.
//     bounds_2 = equal_range(v.begin(), v.end(), 20, comp); // Đoạn [2, 5].
//     cout << bounds_2.first - v.begin() << ' ' << bounds_2.second - v.begin() << en

int main() {
    int t;
    cin >> t;
    while(t > 0) {
        test();
        t--;
    }
    return 0;
}