// http://opc.iarcs.org.in/index.php/problems/BOOKSORT

#include <iostream>
#include <algorithm>
#include <functional>

int a[2000010];
int f[2000010];
int length_min_helper[2000010];

int helper(int *aa, int l, int r, int target) {
    if (aa[l] > target)
        return 0;
    while (l<r) {
        int m = (l+r+1)/2;
        if (aa[m] > target) {
            r = m-1;
        } else {
            l = m;
        }
    }
    return l;
}


int main() {
    int N;
    std::cin >> N;

    for (int i=0;i<N;i++) std::cin >> a[i];

    if (N==1) {
        std::cout << 0 << std::endl;
        return 0;
    }

    f[0] = 1;
    length_min_helper[0] = 0;
    for (int l=1;l<=N;l++) length_min_helper[l] = N+1;
    length_min_helper[1] = a[0];


    for (int i=1;i<N;i++) {
        f[i] = helper(length_min_helper, 1, N, a[i]) + 1;
        if (a[i]<length_min_helper[f[i]]) length_min_helper[f[i]] = a[i];
        // for (int x=0; x<=N;x++) std::cout << length_min_helper[x] << " ";
        // std::cout << std::endl;
        // for (int x=0; x<=i;x++)  std::cout << f[x] << " ";
        // std::cout << std::endl;
    }

    std::cout << N - *std::max_element(f, f+N) << std::endl;

    return 0;
}