// https://www.codechef.com/IOIPRAC/problems/INOI1301

#include <iostream>
// #include <algorithm>

#define SMALLEST_NUM -2147483648

int a[1000000], dp1[1000000], dp2[1000000];

int main() {
    int N, k;
    std::cin >> N >> k;

    if (N<=1) {
        std::cout << 0 << std::endl;
        return 0;
    }

    for (int i=0; i<N; i++) std::cin >> a[i];

    // phrase one
    for (int i=0; i<k-1; i++) dp1[i] = SMALLEST_NUM;
    dp1[k-1] = 0;
    dp1[k] = a[k];
    for (int i=k+1; i<N; i++) dp1[i] = std::max(dp1[i-1], dp1[i-2]) + a[i];
    // phrase two
    dp2[N-1] = dp1[N-1];
    dp2[N-2] = std::max(dp1[N-1] + a[N-2], dp1[N-2]);
    for (int i=N-3; i>=0; i--) dp2[i] = std::max(std::max(dp2[i+1], dp2[i+2]) + a[i], dp1[i]);

    // for (int i=0; i<N; i++) std::cout << dp1[i] << " ";
    // std::cout << std::endl;
    // for (int i=0; i<N; i++) std::cout << dp2[i] << " ";
    // std::cout << std::endl; 

    std::cout << dp2[0] << std::endl;

    return 0;
}