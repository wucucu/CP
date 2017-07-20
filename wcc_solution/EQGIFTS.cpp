// http://opc.iarcs.org.in/index.php/problems/EQGIFTS

#include <iostream>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    int x, y;
    int diff[150];
    for (int i=0; i<N; i++) {
        std::cin >> x >> y;
        diff[i] = std::abs(x-y);
    }

    if (N==1) {
        std::cout << diff[0] << std::endl;
        return 0;
    }

    bool dp[150][45001];

    dp[0][diff[0]] = true;

    for (int i=1; i<N; i++) {
        for (int p=0; p<45001; p++) {
            if (p+diff[i]<45001) dp[i][p+diff[i]] = dp[i][p+diff[i]] ||dp[i-1][p];
            dp[i][std::abs(p-diff[i])] = dp[i][std::abs(p-diff[i])]||dp[i-1][p];
        }
    }

    int p=0;
    while (!dp[N-1][p]) p++;

    std::cout << p << std::endl;

    return 0;
}