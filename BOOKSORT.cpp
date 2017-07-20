#include<bits/stdc++.h>
using namespace std;

int a[200010], dp[200010], f[200010];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = INT_MAX;
    }
    f[0] = 0;

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        int t = lower_bound(f, f+mx+1, a[i]) - f - 1;
        dp[i] = t + 1;
        if (f[dp[i]] > a[i])
            f[dp[i]] = a[i];
        mx = max(mx, dp[i]);
    }
    cout << n - mx << endl;

    return 0;
}
