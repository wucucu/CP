// http://opc.iarcs.org.in/index.php/problems/TILINGS

#include <iostream>
#include <algorithm>

int upper_protruding[1000000], lower_protruding[1000000], flat[1000000];

int main() {
    int N;
    std::cin >> N;

    if (N==1) { std::cout << 1 << std::endl; return 0; }
    if (N==2) { std::cout << 2 << std::endl; return 0; }

    upper_protruding[0] = 0;
    lower_protruding[0] = 0;
    flat[0] = 1;

    upper_protruding[1] = 1;
    lower_protruding[1] = 1;
    flat[1] = 2;

    for (int i=2; i<N; i++) {
        upper_protruding[i] = flat[i-2] + lower_protruding[i-1];
        upper_protruding[i] %= 10000;
        lower_protruding[i] = flat[i-2] + lower_protruding[i-1];
        lower_protruding[i] %= 10000;
        flat[i] = upper_protruding[i-1] + lower_protruding[i-1] + flat[i-1] + flat[i-2];
        flat[i] %= 10000;
    }

    std::cout << flat[N-1] << std::endl;

    return 0;
}