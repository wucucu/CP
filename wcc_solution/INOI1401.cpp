// https://www.codechef.com/IOIPRAC/problems/INOI1401

#include <iostream>
#include <algorithm>


bool is_valid[300][300];
int count_from_left[300][300][300], count_from_up[300][300][300];

int main() {
    int R, C, d;
    std::cin >> R >> C >> d;

    for (int i=0;i<R;i++) 
        for (int j=0;j<C;j++) {
            std::cin >> is_valid[i][j];
            for (int x=0;x<=d;x++) {
                count_from_left[i][j][x]=0;
                count_from_up[i][j][x]=0;
            }
        }
    
    if (R==1 && C==1) {
        std::cout << (int)is_valid[0][0] << std::endl;
        return 0;
    }

    count_from_left[0][0][0] = 1;
    count_from_up[0][0][0] = 1;

    for (int i=0;i<R;i++) 
        for (int j=0;j<C;j++) {
            if (!is_valid[i][j]) continue;
            for (int x=1;x<=d;x++) {
                if (j-1>=0 && is_valid[i][j-1]) count_from_left[i][j][x] = count_from_left[i][j-1][x-1];
                if (i-1>=0 && is_valid[i-1][j]) count_from_up[i][j][x] = count_from_up[i-1][j][x-1];
            }
            for (int x=1;x<=d;x++) count_from_left[i][j][0] += count_from_up[i][j][x] % 20011;
            for (int x=1;x<=d;x++) count_from_up[i][j][0] += count_from_left[i][j][x] % 20011;
        }
    
    // int temp_sum = 0;
    // for (int x=1;x<=d;x++) {
    //     temp_sum += count_from_left[R-1][C-1][x];
    //     temp_sum += count_from_up[R-1][C-1][x];
    // }

    // std::cout << temp_sum << std::endl;

    // for (int j=0;j<C;j++) {
    //     std::cout << count_from_left[2][j][0] << " " << count_from_up[2][j][0] << std::endl;
    // }
    std::cout << (count_from_up[R-1][C-1][0] + count_from_left[R-1][C-1][0]) % 20011 << std::endl;

    return 0;
}