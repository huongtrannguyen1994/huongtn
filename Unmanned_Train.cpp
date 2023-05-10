#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define for_n(i,n) for(int i = 0; i < n; ++i)

struct Point{
    int x;
    int y;
};

void _print(int i) {cout << i;}
void _print(double i) {cout << i;}
void _print(ull i) {cout << i;}
void _print(ll i) {cout << i;}
void _print(const Point& x) {
    cout << "(" << x.x << "," << x.y << ")";
}
template<typename A, typename B>
void _print(pair<A,B>& a) {
    cout << "(" << a.first << "," << a.second << ")"; 
}

template<typename T>
void _print(const T& a){
    cout << "(";
    bool first = true;
    for(auto x:a) {
        cout << (first ? "":","), _print(x);
        first = false;
    }
    cout << ")" << endl;
}

int N,M;
vector<vector<int>> A(50,vector<int>(50));

int mX[4] = {1, -1, 0, 0};
int mY[4] = {0, 0, -1, 1}; 

void findLine(vector<Point>& T, Point p){
    A[p.x][p.y] = 0;
    T.push_back(p);
    for_n(i, 4) {
        int X = p.x + mX[i];
        int Y = p.y + mY[i];
        // cout << N
        if (X < 0 || X >= N) continue;
        if (Y < 0 || Y >= M) continue;
        if (A[X][Y] == 1) {
            Point p1;
            p1.x = X;
            p1.y = Y;
            findLine(T, p1);
        }
    }
}

int caculatorMinDis(Point a, Point b) {
    int dis = a.x > b.x ? a.x - b.x : b.x - a.x;
    dis += a.y > b.y ? a.y -b.y : b.y - a.y;
    dis -= 1;
    return dis;
}

int main() {
    cin >> N >> M;
    A.resize(N);
    for_n(i, N){
        A[i].resize(M);
    }
    for_n(i, N) {
        for_n(j, M) {
            cin >> A[i][j];
        }
    }
    vector<Point> C, D;
    bool first = true;
    for_n(i, N) {
        for_n(j, M) {
            if(A[i][j] == 1 && first == true) {
                Point p;
                p.x = i;
                p.y = j;
                findLine(C, p);
                first = false;
            } else if(A[i][j] == 1 && first == false) {
                Point p;
                p.x = i;
                p.y = j;
                findLine(D, p);
            }
        }
    }
    // _print(D);
    // _print(C);
    int min_Dis = INT_MAX;
    for_n(i, C.size()) {
        for_n(j, D.size()) {
            min_Dis = min(min_Dis, caculatorMinDis(C[i], D[j]));
            // cout << min_Dis << " ";
        }
    }
    cout << min_Dis;
    return 0;
}