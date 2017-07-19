// https://www.codechef.com/ZCOPRAC/problems/ZCO12004

#include <iostream>
#include <algorithm>

int main () {

    int N;
    std::cin >> N;

    if (N<=1) {
        std::cout << 0 << std::endl;
        return 0;
    }

    int a[1000001];
    for (int i=0; i<N; i++) std::cin >> a[i];
    a[N] = 0;

    int c[1000001];
    c[0] = a[0];
    c[1] = a[1];
    for (int i=2; i<N+1; i++) c[i] = std::min(c[i-2], c[i-1]) + a[i];

    std::cout << c[N] << std::endl;
    
    return 0;
}