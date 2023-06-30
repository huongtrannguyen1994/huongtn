#include <bits/stdc++.h>

using namespace std;

long long N, T;
map<int,int> group;
queue<long long> q;
long long ans = 0;

int main() {
    cin >> N >> T;
    vector<long long> A(N,0);
    vector<long long> S(N, 0);
    for(int i=0; i<N; ++i) {
        cin >> A[i] >> S[i];
    }
    q.push(1e31);
    for(int i=N-1; i>=0; --i) {
        long long K = q.front();
        long long  pos = A[i] + 1ll * S[i] * T;
        // cout << pos << " " << K << endl;
        if(pos < K) {
            // cout <<" 1 ";
            ans++;
            q.pop();
            q.push(pos);
        }
    }
    cout << ans;
    return 0;
}