#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;
    while(q--) {
        long long k, n, a, b;
        cin >> k >> n >> a >> b;
        long long l = 0, r = n+1;
        while(l < r) {
            long long m = (r+l)/2;
            if(m*a + (n-m)*b < k) {
                l = m+1;
            } else {
                r = m;
            }
        }
        cout << l-1 << endl;
    }
    return 0;
}