#include <bits/stdc++.h>

using namespace std;
int N, Q;
typedef pair<int,int> rate;
priority_queue<int, vector<int>, greater<int>> rateNum;
int main() {
    cin >> N >> Q;
    vector<vector<int>> Arr(N, vector<int>(N,0));
    for(int i=0; i<Q; ++i) {
        int que, idx, val;
        cin >> que >> idx >> val;
        if (que == 1) {
            for(int j = 0; j < N; ++j) {
                Arr[idx][j] = val;
            }
        } else {
           for(int j = 0; j < N; ++j) {
                Arr[j][idx] = val;
            } 
        }
    }
    int ans = 0;
    for (auto x:Arr) {
        for (auto y:x){
            ans += y;
        }
    }
    cout << ans ;
}