// http://opc.iarcs.org.in/index.php/problems/DIVSEQ

#include <iostream>
#include <algorithm>

int a[10000];
int f[10000];

int main() {
    int N;
    std::cin >> N;

    for (int i=0;i<N;i++) std::cin >> a[i];
    for (int i=0;i<N;i++) f[i] = 1;

    for (int i=1;i<N;i++)
        for (int j=0;j<i;j++)
            if (a[i]%a[j]==0) f[i] = std::max(f[i], f[j]+1);

    std::cout << *std::max_element(f, f+N) << std::endl;

    return 0;
}