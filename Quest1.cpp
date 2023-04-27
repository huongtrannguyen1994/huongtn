#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for(int i=0; i<n; i++)
#define ll long long

void test_script() {
    int n, d;
    ll c;
    cin >> n >> c >> d;
    std::vector<ll> a(n), temp(d,0);
    for(auto& x : a) {
        cin >> x;
    }
    
    sort(a.rbegin(), a.rend());
    if ((a[0] * d) < c) {
        cout << "Impossible" << endl;
        return;
    }
    temp[0] = a[0];
    for(int i = 1; i < d; ++i) {
        if (i<n) temp[i] = a[i] + temp[i-1];
        else temp[i] += temp[i-1];
    }
    // if (temp[d-1] >= c) {
    //     cout << "Infinity" << endl;
    //     return;
    // }
    // for(auto&x:temp){
    //     cout << x << " ";
    // }
    int l = 0, r = d-1, m = 0;
    ll tt = 0;
    forn(i,d) {
        tt = ((d-1)/(i+1))*temp[i] + temp[(d-1)%(i+1)];
        if (i == d-1 && tt >= c) cout << "Infinity" << endl;
        else if (tt < c) {
            cout << i-1 << endl;
            return;
        }
    }
    return;
}
 
int main()
{
    int n;
    cin >> n;
    // vector<string> a(n);
    forn(i, n) {
        test_script();
    }
    // forn(i, n) {
    //     cout << a[i] << endl;
    // }
    return 0;
}