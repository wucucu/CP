// https://www.commonlounge.com/discussion/cbb1cf5102e24774a2bd43daa5211230

#include <iostream>

int dp[110][110];
int f[110];
int g[110];
int a[110];



int main() {
    int tt;
    std::cin >> tt;

    while (tt--) {
        int n;
        std::cin >> n;
        for (int i=0;i<110;i++) for (int j=0;j<110;j++)
            dp[i][j] = 0;
        for (int i=0;i<110;i++) {a[i]=0; f[i]=0; g[i]=0;}
        for (int i=0;i<n;i++) std::cin >> a[i];
        // a[n] = 101;
        // a[n+1] = 0;

        for (int i=0; i<n; i++) {
            f[i] = 1;
            g[i] = 1;
            for (int j=0; j<i; j++) {
                if (a[j]<a[i]) f[i] = std::max(f[j]+1, f[i]);
                if (a[j]>a[i]) g[i] = std::max(g[j]+1, g[j]);
            }
        }

        for (int k=0; k<n; k++) {
            dp[k][k] = 1;
            for (int i=0; i<k; i++) {
                dp[i][k] = f[i]+1;
                dp[k][i] = g[i]+1;
                for (int j=0; j<k; j++) {
                    if (a[j] < a[k]) {
                        dp[k][i] = std::max(dp[j][i]+1, dp[k][i]);
                    }                    
                    if (a[j] > a[k]) {
                        dp[i][k] = std::max(dp[i][j]+1, dp[i][k]);
                    }
                }
            }
        }

        // std::cout << std::endl;
        // for (int x=0; x<n; x++) {
        //     for (int y=0; y<n; y++) std::cout << dp[x][y] << " ";
        //     std::cout << std::endl;
        // }


        int m = 0;
        for (int x=0; x<n; x++)
            for (int y=0; y<n; y++) m = std::max(m, dp[x][y]);

        std::cout << m << std::endl;
    }
}