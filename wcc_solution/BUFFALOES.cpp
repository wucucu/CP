// http://opc.iarcs.org.in/index.php/problems/BUFFALOES

#include <iostream>
#include <algorithm>

int f[2][410];
int a[410];


int main() {
    int n,k;
    std::cin >> n >> k;

    for (int i=0; i<n; i++) std::cin >> a[i];

    k = k/2;

    for (int i=0; i<n; i++) {f[0][i] = 0; f[1][i] = 0;}

    // for (int x=0; x<n; x++) std::cout << f[0][x] << " ";
    // std::cout << std::endl;

    if (k>=1) {
        for (int i=1; i<n; i++) {
            int u = a[i] - *std::min_element(a, a+i);
            f[1][i] = std::max(0, u);
        }
    }
    
    // for (int x=0; x<n; x++) std::cout << f[1][x] << " ";
    // std::cout << std::endl;

    for (int t=2; t<=k; t++) {
        for (int i=0; i<n; i++) {
            f[t%2][i] = f[(t-1)%2][i];
            for (int j=0; j<i-1; j++) {
                f[t%2][i] = std::max(f[(t-1)%2][j] - *std::min_element(a+j+1, a+i) + a[i], f[t%2][i]);

                // std::cout << "i " << i <<" "<< "j " << j << " ";
                // for (int x=0; x<n; x++) std::cout <<f[t%2][x] << " ";
                // std::cout << std::endl;
            }
        }

    }

    std::cout << *std::max_element(f[k%2], f[k%2]+n) << std::endl;

}