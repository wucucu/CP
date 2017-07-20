// http://www.spoj.com/problems/ALTSEQ/

#include <iostream>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    int a[5000];
    for (int i=0;i<N;i++) std::cin >> a[i];

    int f[5000];
    f[0] = 1;
    for (int i=1;i<N;i++) {
        f[i] = 1;
        for (int j=0;j<i;j++) {
            if ((a[j]>0&&a[i]<0&&a[j]<-a[i])||(a[j]<0&&a[i]>0&&-a[j]<a[i])) f[i] = std::max(f[i], f[j]+1);
        }
    }

    std::cout << *std::max_element(f, f+N) << std::endl;

    return 0;
}