#include <bits/stdc++.h>

using namespace std;

int N, A, B;
unsigned long long K;

void solve() {
    int r = N;
    int l = 0;

    while(l < r) {
        int av = (r + l)/2;
        // cout << " av: " << av;
        unsigned long long sum = (1LL*av * A) + (1LL*(N-av) * B);
        // cout << " " << sum;
        if(sum >= K) {
            r = av;
        } else {
            l = av + 1;
        }
        cout << " r l: " << r << l;
    }
    // cout <<  endl;
    cout << " r1 l1: " << r << l;
    // if(r == N && r < 0) {
    //     cout << "-1" << endl;
    // } else {
    //     cout << r << endl;
    // }
}
int main() {
    int n;
    cin >> n;
    while(n--) {
        cin >> K >> N >> A >> B;
        solve();
    }

    return 0;
	
}