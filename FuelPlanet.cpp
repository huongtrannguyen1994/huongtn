#include <bits/stdc++.h>

using namespace std;

int T, N, D, C;
int ans = 0;
int cur_Fuel = 0, cur_Price_Unit = 0;
int volume = 0;
set<pair<int, int>> tank;

int solve(vector<int>& A) {
    // cout << " 1";
    for(int i=0; i<N; ++i) {
        // cout <<" 2";
        while(!tank.empty() && tank.begin()->first < A[i]) {
            volume -= tank.begin()->second;
            tank.erase(tank.begin());
            cout << " volume" << volume;
        }
        // cout << " 3";
        int addFuel = C - volume;
        pair<int, int> tem = {A[i], addFuel};
        tank.insert(tem);
        volume += C - volume;

        int remainD = D;
        while(remainD > 0) {
            // cout << " 3";
            auto it = tank.end();
            it--;
            if(remainD >= it->second) {
                ans += (it->second * it->first);
                remainD -= it->second;
                tank.erase(it);
                cout << " ans" << ans;
            } else {
                ans += remainD * it->first;
                pair<int, int> tem1 = {it->first, it->second - remainD};
                tank.erase(it);
                tank.insert(tem1);
                remainD = 0;
                cout << " ans" << ans;
            }
        }
        // cout << " 4";
        volume -= D;


    }
    cout << "ans" << ans;
    return ans;
}

int main() {
    cin >> T;
    while(T--) {
        cin >> N >> C >> D;
        vector<int> A(N);
        for(auto& x:A) {
            cin >> x;
        }
        cout << solve(A) << endl;
    }
    return 0;
}