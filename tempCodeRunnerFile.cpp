#include <bits/stdc++.h>

using namespace std;

int N, A, B;
unsigned long long K;

void solve() {
    int r = N;
    int l = 0;

    while(l <= r) {
        int av = (r + l)/2;
        // cout << " av: " << av;
        unsigned long long sum = (av * A) + ((N-av) * B);
        // cout << " " << sum;
        if(sum >= K) {
            r = av - 1;
        } else {
            l = av + 1;
        }
        // cout << " r l: " << r << l;
    }
    // cout <<  endl;
    // cout << " r1 l1: " << r << l;
    if(r == N && r < 0) {
        cout << "-1" << endl;
    } else {
        cout << r << endl;
    }
}
int main() {
    int n;
    cin >> n;
    while(n--) {
        cin >> K >> N >> A >> B;
        solve();
    }
    // int q;
	// cin >> q;
	// for (int i = 0; i < q; ++i) {
	// 	long long k, n, a, b;
	// 	cin >> k >> n >> a >> b;
	// 	k -= n * a;
	// 	if (k > 0) {
	// 		cout << n << endl;
	// 	} else {
	// 		k = -k;
	// 		++k;
	// 		long long diff = a - b;
	// 		long long turns = (k + diff - 1) / diff;
	// 		if (turns > n) {
	// 			cout << -1 << '\n';
	// 		} else {
	// 			cout << n - turns << '\n';
	// 		}
	// 	}
	// }
    return 0;
	
}