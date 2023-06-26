#include <bits/stdc++.h>

using namespace std;

int N = 5;
vector<int> A = {1, 3, 5, 7, 9};

void Solve(){
    int value, cnt=0, from=0;
    cout << N << endl;
    value = A[from];
    while (cnt < N){
        while (value == 0){
            from = (from + 1) % N;
            value = A[from];
        }
        cout << value << " ";
        cnt++;
        A[from] = 0;
        from = (value + from) % N;
        value = A[from];
    }
}

int main() {
    Solve();
    return 0;
}