#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for(int i=0; i<n; i++)
#define ll long long
int caculator(vector<ll> a, int d, int k, ll c) {
    int rst = 0, cnt = 0;
    ll sum = 0;
    // cout << "size:" << a.size(); 
    while (cnt < d) {
        forn(i, k) {
            if (i < a.size()) {
                sum += a[i];
            }
            // cout << "'" << i << ": " << a[i] << "'"; 
            cnt++;
            if (cnt >= d) break;
        }
    }
    if (sum > c) {
        // cout << "k+1: " << k+1;
        return caculator(a, d, k+1, c);
    } else if (sum == c) {
        // cout << "k-1: " << k-1;
        return k-1;
    } else {
        // cout << "k-2: " << k-2;
        return k-2;
    }
    return rst;
}
string test_script() {
    string s = "";
    int n, d;
    ll c;
    cin >> n >> c >> d;
    std::vector<ll> a(n);
    for(auto& x : a) {
        cin >> x;
    }
    
    sort(a.rbegin(), a.rend());
    int temp = c / a[0];
    bool check = temp > d ? true : false;
    if (check == false && temp == d) {
        if ((c % a[0]) != 0) check = true;
    }
    
    if (a[0] >= c) {
        // cout << "Infinity" << endl;
        s = "Infinity";
        return s;
    }
    if (check == true) {
        // cout << "Impossible" << endl;
        s = "Impossible";
        return s;
    }
    temp = c / a[0];
    int temp1 = c % a[0];
    temp = d / temp;
    int temp2 = d / temp;
    if (temp1 == 0 && temp2 == 0) {
        s = to_string(temp);
        // cout << temp << endl;
        return s;
    }
    int k = temp+1;
    // cout << caculator(a, d, k, c) << endl;
    s = to_string(caculator(a, d, k, c));
    return s;
}
 
int main()
{
    int n;
    cin >> n;
    vector<string> a(n);
    forn(i, n) {
        a[i] = test_script();
    }
    forn(i, n) {
        cout << a[i] << endl;
    }
    return 0;
}