#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int D[n+1];
    int T[n+1];
    int modu = 1e9 + 7;
    D[0] = 0; D[1] = 1; D[2] = 2;
    T[0] = 0; T[1] = 0; T[2] = 1;

    for(int i=3; i <= n; ++i) {
        D[i] = ((D[i-1] + D[i-2]) % modu + (2 * T[i-1]) % modu) % modu;
        T[i] = (D[i-2] + T[i-1]) % modu;
    }
    cout << D[n];
    return 0;
}