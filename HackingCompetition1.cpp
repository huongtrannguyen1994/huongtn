#include <bits/stdc++.h>

using namespace std;

string S, C;
int sizeS, sizeC, sizeL, sizeR;

int cursor;
stack<char> Left, Right;
string ans = "";

void changeFollowC(char c) {
    if (c == 'L') {
        if(!Left.empty()) {
            char x = Left.top();
            Left.pop();
            Right.push(x);
        }
    } else if (c == 'R') {
        if(!Right.empty()) {
            char x = Right.top();
            Right.pop();
            Left.push(x);
        }
    } else if (c == 'B') {
        if(!Left.empty()) {
            Left.pop();
        }
    } else {
        Left.push(c);
    }
    // cout << "Left: " << Left << " Right: " << Right << endl;
}

void solve() {
    for(int i = 0; i < sizeC; ++i) {
        char c = C[i];
        changeFollowC(c);
    }
    while(!Left.empty()) {
        char c = Left.top();
        ans += c;
        // cout << c << " ";
        Left.pop();
    }
    reverse(ans.begin(), ans.end());
    
    while(!Right.empty()) {
        char c = Right.top();
        ans += c;
        // cout << c;
        Right.pop();
    }
    cout << endl;
    for(auto x:ans) {
        cout << x;
    }
}

int main() {
    cin >> S >> C;
    sizeS = S.length();
    sizeC = C.length();
    for(auto x: S) {
        Left.push(x);
    }
    // cout << Left[sizeS-1];
    // // Left.erase(Left.begin()+sizeS-1);
    // Left.erase(Left.begin());
    // sizeS = Left.length();
    // cout << Left[0];
    // cout << sizeS << sizeC;
    solve();
    return 0;
}