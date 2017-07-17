// http://opc.iarcs.org.in/index.php/problems/NEXTPERM

#include <iostream>
#include <algorithm>

int N, K;

int hasNextPerm(int *a, int l, int r) {
    for (int i=l; i<r; i++) {
        if (a[i]<a[i+1]) return 1;
    }
    return 0;
}

int nperm(int *a, int l, int r) {
    int flag = hasNextPerm(a, l, r);

    if (hasNextPerm(a, l+1, r)) {
        nperm(a, l+1, r);
    } else {
        int i=l+1, j=r;
        int temp;
        while (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
        int swap_ind = l+1;
        for (;a[l]>a[swap_ind];swap_ind++) {}
        temp = a[l];
        a[l] = a[swap_ind];
        a[swap_ind] = temp;
    }

    return flag;
}

int main() {
    // int N, K;
    std::cin >> N >> K;

    int a[1000];
    while (K--) {
        for (int i=0; i<N; i++) {
            std::cin >> a[i];
        }
        nperm(a, 0, N-1);
        for (int i=0; i<N; i++) {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}