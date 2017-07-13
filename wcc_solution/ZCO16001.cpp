// https://www.codechef.com/ZCOPRAC/problems/ZCO16001

#include <iostream>
#include <algorithm>

int solve(int *a, int *b, int N, int k0, int k) {

    if (*(a+N-1) <= *b) {
        return *(a+N-1) + *(b + N - 1);
    }

    if (k0 == k)
        return *(a + N - k - 1) + std::max(*(a + N - 1), *(b + N - 1)); 

    if (*(a + N - k - 1) >= *(b + k - 1)) {
        return *(a + N - k - 1) + std::max(*(a + N - 1), *(b + N - 1));
    } else {
        int mid_k = (k0+k) / 2;
        if (*(a + N - mid_k - 1) >= *(b + mid_k - 1)) {
            return solve(a, b, N, mid_k, k - 1);
        } else {
            return solve(a, b, N, k0, mid_k - 1);
        }
    }
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

    std::cout << std::min(solve(a, b, N, 1, K), solve(b, a, N, 1, K)) << std::endl;

    return 0;

}