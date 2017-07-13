// https://www.codechef.com/ZCOPRAC/problems/ZCO16001

#include <iostream>
#include <algorithm>

int solve(int *a_ori, int *b_ori, int N, int k) {
    int a[N], b[N];
    for (int i=0; i<N; i++) {
        a[i] = a_ori[i];
        b[i] = b_ori[i];
    }
    int min_skew = *(a+N-1) + *(b+N-1);
    while (k--) {
        std::iter_swap(a, b+N-1);
        std::sort(a, a+N);
        std::sort(b, b+N);
        int skew = *(a+N-1) + *(b+N-1);
        if (skew > min_skew) {
            break;
        } else {
            min_skew = skew;
        }
    }

    return min_skew;

}


int main() {

    int N, K;
    std::cin >> N >> K;

    K = std::min(N/2, K);

    int a[N];
    int b[N];

    for (int i=0; i<N; i++) {
        std::cin >> a[i];
    }
    for (int i=0; i<N; i++) {
        std::cin >> b[i];
    }

    std::sort(a, a+N);
    std::sort(b, b+N);

    std::cout << std::min(solve(a, b, N, K), solve(b, a, N, K)) << std::endl;

    return 0;

}