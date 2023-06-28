#include <bits/stdc++.h>

using namespace std;
int N;
typedef pair<int,int> rate;
priority_queue<rate> rateNum;

map<int,int> money;
int ans;

void dp(int idx, vector<int>& R) {
    cout << ans << " ";
    if(idx != N-2) {
        ans = max(money[idx] + R[idx+2], R[idx+1]);
        money[idx+2] = ans;
        money[idx+1] = money[idx];
        dp(idx+1, R);
    } else {
        // ans = max(money[idx] + R[idx+2], R[idx+1]);
        return;
    }
}
int main() {
    cin >> N;
    vector<int> R(N, 0);
    for(int i = 0; i < N; ++i) {
        int r;
        cin >> r;
        pair<int,int> tem = {r , i};
        rateNum.push(tem);
        R[i] = r;
    }
    if(N == 0) {
        cout << "0";
        return 0;
    }
    if(N == 1) {
        cout << R[0];
        return 0;
    }
    money[0] = R[0];
    dp(0, R);
    cout << ans;
    return 0;
    
}