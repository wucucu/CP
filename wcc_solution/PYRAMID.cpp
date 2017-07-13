// http://opc.iarcs.org.in/index.php/problems/PYRAMID

#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int M;
    std::cin >> M;

    int a[1000000];

    int x, y;

    for (int i=0; i<M; i++) {
        std::cin >> x >> y;
        a[i] = x<y ? x : y; 
    }

    std::sort(a, a+M);

    int i = 0;
    int height = 0;
    while (i<M) {
        while (i<M && a[i]<height+1) i++;
        if (i<M) {i++; height++;}
    }

    std::cout << height << std::endl;
}