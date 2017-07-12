#include<bits/stdc++.h>
using namespace std;

vector<int> a;
vector<int> b;
int n;

int solve() {
    b.erase(b.begin(), b.end());
    if (n == 1)
        return a[0];
    b.push_back(a[0]);
    b.push_back(a[0] + a[1]);
    for (int i = 2; i < n; i++) {
        b.push_back(min(b[i-1], b[i-2]) + a[i]);
    }
    return min(b[n-1], b[n-2]);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    int mn = solve();
    reverse(a.begin(), a.end());
    mn = min(mn, solve());
    cout << mn << endl;
    return 0;
}
