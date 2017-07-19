// https://www.codechef.com/ZCOPRAC/problems/ZCO14002

#include <iostream>
#include <algorithm>

int main() {

    int N;
    std::cin >> N;

    int a[200000];
    for (int i=0; i<N; i++) std::cin >> a[i];

    if (N<=2) {
        std::cout << 0 << std::endl;
    }

    int f[200000];
    f[0] = a[0];
    f[1] = a[1];
    f[2] = a[2];
    for (int i=3; i<N; i++) f[i] = *std::min_element(f+i-3, f+i) + a[i];

    std::cout << *std::min_element(f+N-3, f+N) << std::endl;

    return 0;
}