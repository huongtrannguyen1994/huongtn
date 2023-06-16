#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> P(10^5, 0), V(10^5, 0), T(10^5, 0);
vector<vector<int>> C;
int ans = 0;

bool compareColor(vector<int>& A, vector<int>& B) {
    bool check = true;
    for(int i=0; i<N; ++i) {
        if (A[i] != B[i]) {
            check = false;
            break;
        }
    }
    return check;
}

void dfs(int idx) {
    if (compareColor(V, T)) {
        return ans;
    }
    queue<int> q;
    q.push(idx);
    
}

int main() {
    cin >> N;
    P.resize(N+1);
    V.resize(N+1);
    C.resize(N+1);
    T.resize(N+1);
    for(int i = 2; i <= N; i++) {
        cin >> P[i];
        C[P[i]].push_back(i);
    }
    for(int i = 1; i <= N; i++) cin >> V[i];

    for(auto p:P) cout << p << " ";

    return 0;
	
}