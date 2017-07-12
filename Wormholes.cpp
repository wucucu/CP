#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int> > a; 
vector<int> V;
vector<int> W;
int main() {
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        a.push_back(make_pair(u, v));
    }
    for (int i = 0; i < x; i++) {
        int u;
        cin >> u;
        V.push_back(u);
    }
    sort(V.begin(), V.end());
    for (int i = 0; i < y; i++) {
        int u;
        cin >> u;
        W.push_back(u);
    }
    sort(W.begin(), W.end());
    int ans = 1000020;
    for (auto it = a.begin(); it != a.end(); it++) {
        if (*V.begin() > it->first) continue;
        if (*W.rbegin() < it->second) continue;
        vector<int>::iterator l = --upper_bound(V.begin(), V.end(), it->first);
        vector<int>::iterator r = lower_bound(W.begin(), W.end(), it->second);
        ans = min(ans, *r - *l + 1);
    }
    cout << ans << endl;
    return 0;
}
