#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> P;
typedef pair<int,int> money;
priority_queue<money, vector<money>, greater<money>> Q;
int main() {
    cin >> N >> M;
    P.resize(N+1);
    vector<vector<int>> F(N+1);
    for(int i = 1; i<= N; ++i) {
        int num;
       cin >> num;
       pair<int,int> a = {num, i};
       Q.push(a);
    }
    for(int i=1; i<= M; ++i) {
        int a, b;
        cin >> a >> b;
        F[a].push_back(b);
        F[b].push_back(a);
    }

    queue<int> q;
    vector<bool> visit(N+1, false);
    int ans = 0;
    while(!Q.empty()) {
        int idx = Q.top().second;
        int m = Q.top().first;
        Q.pop();
        cout << idx << " ";
        if(visit[idx] == false) {
            visit[idx] = true;
            q.push(idx);
            while(!q.empty()) {
                int idx1 = q.front();
            }
            ans += m;
            for(auto& x:F[idx]){
                visit[x] = true;
            }
        }
    }
    cout << "\n";
    cout << ans ;
    return 0;
}