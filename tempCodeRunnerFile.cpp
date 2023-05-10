#include <bits/stdc++.h>

using namespace std;

int N, D, C;
vector<int> A;

template<typename T>
void _print(const vector<T>& a) {
    // cout << "{";
    for(auto& x:a) {
        cerr << x;
    }
    // cout 
}



int main() {

    int T;
    cin >> T;
    while(T--) {
        cin >> N >> D >> C;
        A.resize(N);

        for(auto& x:A) {
            cin >> x;
        }
        _print(A);
    }
    return 0;
}