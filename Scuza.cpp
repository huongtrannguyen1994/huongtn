#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n)  for(int i=0; i<n; i++)
#define ll long long
ll caculator(vector<int>& a, vector<int>& b) {
    forn(i, b.size()) {
        ll sum = 0;
        forn(j, a.size()) {
            if (b[i] >= a[j]) {
                sum += a[j];
            } else break;
        }
        // rst.push_back(sum);
        cout << sum << " ";
    }
}
void test_script() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(q);
    // vector<ll> rst;
    for(auto& x:a) {
        cin >> x;
    }
    for(auto& x:b) {
        cin >> x;
    }
    caculator(a, b);
    cout << endl;
    // return rst;
}
 
int main() {
    int n;
    cin >> n;
    // map<int, vector<ll>> m;
    forn(i, n) {
        test_script();
    }
    // forn(i, n) {
    //     for(auto x: m[i]) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}