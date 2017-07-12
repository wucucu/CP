#include<bits/stdc++.h>
using namespace std;

vector<int> a;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back(min(x, y));
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > ans) ans++;
    }
    cout << ans << endl;
    return 0;
}
