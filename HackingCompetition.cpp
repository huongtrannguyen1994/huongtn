#include <bits/stdc++.h>

using namespace std;

string S, C;
int sizeS, sizeC, sizeL, sizeR;

int cursor;
string Left, Right;

void changeFollowC(char c) {
    sizeL = Left.length();
    sizeR = Right.length();
    if (c == 'L' && sizeL != 0) {
        Right.insert(Right.begin(), Left[sizeL-1]);
        Left.erase(Left.end()-1);
    } else if (c == 'R' && sizeR != 0) {
        Left += Right[0];
        Right.erase(Right.begin());
    } else if (c == 'B' && sizeL != 0) {
        Left.erase(Left.end()-1);
    } else {
        Left += c;
    }
    // cout << "Left: " << Left << " Right: " << Right << endl;
}

void solve() {
    for(int i = 0; i < sizeC; ++i) {
        char c = C[i];
        changeFollowC(c);
    }
    S = Left + Right;
    // cout << endl;
    cout << S;
}

int main() {
    cin >> S >> C;
    sizeS = S.length();
    sizeC = C.length();
    cursor = sizeS+1;
    Left = S;
    Right = "";
    // cout << Left[sizeS-1];
    // // Left.erase(Left.begin()+sizeS-1);
    // Left.erase(Left.begin());
    // sizeS = Left.length();
    // cout << Left[0];
    // cout << sizeS << sizeC;
    solve();
    return 0;
}