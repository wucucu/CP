#include<bits/stdc++.h>
using namespace std;

const int P = 20011;

int a[310][310];
int dp1[310][310][310];
int dp2[310][310][310];
int main() {
    int r, c, d;
    cin >> r >> c >> d;
    for (int i = 1; i <= r; i++) 
        for (int j = 1; j <= c; j++)
            cin >> a[i][j];

    dp1[1][1][0] = 1;
    dp2[1][1][0] = 1;
    for (int i = 1; i <= r; i++) 
        for (int j = 1; j <= c; j++){
            if (a[i][j] == 0)
                continue;
            for (int k = 1; k <= d; k++) {
                dp1[i][j][k] = dp1[i-1][j][k-1];
                dp2[i][j][k] = dp2[i][j-1][k-1];
                dp1[i][j][k] %= P;
                dp2[i][j][k] %= P;
            }
            for (int k = 1; k <= d; k++) {
                dp1[i][j][0] += dp2[i][j][k];
                dp2[i][j][0] += dp1[i][j][k];
                dp1[i][j][0] %= P;
                dp2[i][j][0] %= P;
            }
        }
    int ans = 0;
    for (int i = 1; i <= d; i++) {
        ans += dp1[r][c][i] + dp2[r][c][i];
        ans %= P;
    }
    cout << ans << endl;
    return 0;
}
