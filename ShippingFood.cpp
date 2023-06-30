#include <bits/stdc++.h>

using namespace std;

int N,H;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> T_Fee_PD;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> T_Fee_PD_backup;

int ans = 0, cnt =0 , ans_bk = 0, cnt_bk =0 ;

int main() {
    cin >> N >> H;
    vector<int> M(N, 0);
    vector<int> F(N, 0);
    for(auto &x:M) cin >> x;
    for(auto &x:F) cin >> x;

    int idx_max_fee = max_element(F.begin(), F.end()) - F.begin();

    for(int i=0; i<N; ++i) {
        if(F[idx_max_fee] == F[i]) {
            if (M[idx_max_fee] > M[i]) idx_max_fee = i;
        }
    }

    for(int i=0; i<N; ++i) {
        int t = M[i] + F[i];
        if(i == idx_max_fee) {
            T_Fee_PD.push({M[i], i});
            T_Fee_PD_backup.push({M[i], i});
        } else {
            T_Fee_PD.push({t, i});
            T_Fee_PD_backup.push({t, i});
        }
    }
    bool check_backup = fasle;
    for(int i=0; i<N; ++i) {
        int f = T_Fee_PD.top().first;
        int idx = T_Fee_PD.top().second;
        T_Fee_PD.pop();
        ans += f;
        if(idx == idx_max_fee) check_backup = true;
        if (H < ans) {
            ans -= f;
            break;
        }
        cnt++;

    }
    if (!check_backup) {

    }
    cout  << cnt << " " << ans;


    return 0;
}