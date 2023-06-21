#include <bits/stdc++.h>

using namespace std;

struct Obj 
{
    vector<int> item;

};
#define vari pair<int, int>
priority_queue<vari, vector<vari>, greater<vari>> q;
// vector<int> save;

void print_R(int d, vector<int>& save) {
    cout << d <<endl;
    for(auto x:save) {
        cout << x << " ";
    }
    cout << endl;
}
bool check (vector<int>& A, int v) {
    for(auto x:A) {
        if (x == v) return false;
    }
    return true;
}

void solve(vector<Obj>& A, int N) {
    pair<int, int> p = {0, 1};
    vector<bool> visit(N, false);
    q.push(p);
    vector<int> preV(N, 0);
    preV[1] = 0;
    vector<int> save;
    while(!q.empty()) {
        int v = q.top().second;
        int d = q.top().first;
        // cout << " d: " << d << " ";
        q.pop();
        if(preV[v] != 0 && (find(save.begin(), save.end(), preV[v]) == save.end())) {
            save.push_back(preV[v]);
        }
        visit[v] = true;
        for(auto x : A[v].item) {
            if(x == N) {
                if (find(save.begin(), save.end(),v) == save.end()) save.push_back(v);
                print_R(d+1, save);
                return;
            }
            pair<int, int> p1 = {(d+1), x};
            preV[x] = v;
            q.push(p1);
        }
    }
    cout << "-1" << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--){
        int N;
        cin >> N;
        vector<Obj> A(N);
        for(int i=1; i<N; ++i){
            int T1;
            cin >> T1;
            for(int j=0; j<T1; ++j){
                int T2;
                cin >> T2;
                A[i].item.push_back(T2);
            }
        }
        // cout << A[1].item[0];
        solve(A, N);
    }
    return 0;
}