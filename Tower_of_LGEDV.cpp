#include <bits/stdc++.h>

using namespace std;
int N;
typedef pair<int,int> rate;
priority_queue<int, vector<int>, greater<int>> rateNum;
int main() {
    cin >> N;
    vector<int> boss(N, 0);
    vector<int> spirit(N, 0);
    for (auto& x: boss) {
        cin >> x;
    }
    for (auto& x: spirit) {
        cin >> x;
    }
    for (int i = 0; i < N; ++i) {
        while(!rateNum.empty()) {
            int spi = rateNum.top();
            if(spi < boss[i]) {
                rateNum.pop();
            } else {
                break;
            }
        }
        rateNum.push(spirit[i]);
    }
    cout << rateNum.size();
    return 0;
}