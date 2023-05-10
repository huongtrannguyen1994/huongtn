#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

ull N, D, C;
vector<ull> Fuel;
vector<int> cfg;
int dis, max_dis = 0;
set<pair<ull, ull>> tank;

void _print(int i) {cout << i;}
template<typename T>
void _print(const T& a) {
    bool first = true;
    cout << "(";
    for(auto& x:a) {
        cout << (first ? "":","), _print(x);
        first = false;
    }
    cout << ")";
}

void solve() {
    ull res = 0;
    ull volume = 0; // luong nhien lieu dang co
    for(int i = 0; i < N; ++i){
        while(!tank.empty() && tank.begin()->first <= Fuel[i]) {
            volume -= tank.begin()->second;
            // cout << "first: " << tank.begin()->first
            //     << " second: "<< tank.begin()->second << endl;
            tank.erase(tank.begin());
        }
        // cout << "volume: " << volume << endl;
        tank.insert({Fuel[i], C - volume});
        volume += C - volume;
        ull remainD = D;
        while(remainD > 0){
            auto it = tank.end();
            it--;
            // cout << "first: " << it->first
            //     << " second: "<< it->second << endl;
            if(remainD >= it->second) {
                res += it->second * it->first;
                remainD -= it->second;
                tank.erase(it);
            } else {
                res += remainD * it->first;
                pair<ull, ull> tem = {it->first, it->second - remainD};
                tank.erase(it);
                tank.insert(tem);
                remainD = 0;
            }
            // cout << res << endl;
        }
        volume -= D;
    }
    cout << res;
    
}


int main() {

    int T;
    cin >> T;
    while(T--) {
        cin >> N >> C >> D;
        Fuel.resize(N);

        for(auto& x:Fuel) {
            cin >> x;
        }
    }
    solve();
    return 0;
}