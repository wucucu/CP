// https://www.codechef.com/ZCOPRAC/problems/ZCO12002

#include <iostream>
#include <algorithm>
#include <functional>

int main() {
    int N, X, Y;
    std::cin >> N >> X >> Y;

    int b[100000];
    int e[100000];
    int v[100000];
    int w[100000];

    for (int i=0; i<N; i++) std::cin >> b[i] >> e[i];
    for (int i=0; i<X; i++) std::cin >> v[i];
    for (int i=0; i<Y; i++) std::cin >> w[i];

    std::sort(v, v+X, std::greater<int>());
    std::sort(w, w+Y);

    // for (int i=0; i<X; i++) std::cout << v[i] << " ";
    // std::cout << std::endl;
    // for (int i=0; i<Y; i++) std::cout << w[i] << " ";
    // std::cout << std::endl;

    int *enter_pointer;
    int *exit_pointer;
    int min_cost = 0;
    int curr_cost;
    for (int i=0; i<N; i++) {
        enter_pointer = std::lower_bound(v, v+X, b[i], std::greater<int>());
        exit_pointer = std::lower_bound(w, w+Y, e[i]);

        // std::cout << *enter_pointer << *exit_pointer << std::endl;
        // std::cout << enter_pointer << " " << v + X << std::endl;

        if (enter_pointer==v+X || exit_pointer==w+Y) continue;

        curr_cost = *exit_pointer - *enter_pointer + 1;

        if (min_cost==0 || curr_cost < min_cost) min_cost = curr_cost;
        // std::cout << curr_cost << std::endl;
    }

    std::cout << min_cost << std::endl;
}