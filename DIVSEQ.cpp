#include<bits/stdc++.h>
using namespace std;

int a[10010], dp[10010];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] % a[j] == 0 && dp[j]+1 > dp[i])
                dp[i] = dp[j] + 1;
        }
    }
    cout << *max_element(dp, dp+n) << endl;
    return 0;
}
