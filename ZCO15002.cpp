#include<bits/stdc++.h>
using namespace std;

vector<int> a;
long long ans;

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    vector<int>::iterator r = a.begin();
    for (int i = 0; i < n; i++) {
        r = lower_bound(r, a.end(), a[i]+k);
        if (r == a.end()) break;
        ans += a.end() - r;
    }
    cout << ans << endl;
    return 0;
}
