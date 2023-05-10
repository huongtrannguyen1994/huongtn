#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define for_n(i, n) for(int i = 0; i < n; ++i)

void _print(int i) {cout << i;}
void _print(double i) {cout << i;}
void _print(ull i) {cout << i;}
void _print(ll i) {cout << i;}
template<typename A, typename B>
void _print(pair<A,B>& a) {
    cout << "(" << a.first << "," << a.second << ")";
}

template<typename A>
void _print(const A& a) {
    cout << "(";
    bool first = true;
    for(auto x:a) {
        cout << (first ? "":","), _print(x);
        first = false;
    }
    cout << ")" <<endl;
}

int N,M;

int minDistance(vector<int>& dis, vector<bool>& visit) {
    int min = INT_MAX, idxMin;
    for_n(i, N) {
        if(!visit[i] && dis[i] < min) {
            min = dis[i];
            idxMin = i;
        }
    }
    return idxMin;
}

void dijkstras(vector<vector<int>>& facDis) {
    vector<int> maxDisVetical;
    for_n(i, N) {
        vector<int> dis(N, INT_MAX);
        vector<bool> visit(N, false);
        dis[i] = 0;

        for_n(j, N-1) {
            int u = minDistance(dis, visit);
            visit[u] = true;
            for_n(v, N) {
                if(!visit[v] && dis[u] != INT_MAX 
                && facDis[u][v] != 0 
                && dis[v] > dis[u] + facDis[u][v])
                dis[v] = dis[u] + facDis[u][v];
            }
        }
        int maxVetical = max_element(dis.begin(), dis.end()) - dis.begin();
        // _print(dis);
        // _print(maxVetical);
        maxDisVetical.push_back(dis[maxVetical]);
    }
    // _print(maxDisVetical);
    int ans = min_element(maxDisVetical.begin(), maxDisVetical.end()) - maxDisVetical.begin();
    cout << maxDisVetical[ans];
}

int main() {
    cin >> N >> M;
    vector<vector<int>> facDis(N, vector<int>(N, 0));
    for_n(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        facDis[--a][--b] = c;
        facDis[b][a] = c;
    }
    // _print(facDis);
    dijkstras(facDis);
    return 0;
}