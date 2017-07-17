// http://www.spoj.com/problems/AGGRCOW/

#include <iostream>
#include <algorithm>

int try_solution(int *a, int n, int c, int interval) {
    int left_c = c;
    int left_n = n;

    if (c==0 && c>n) return 0;

    int curr_ind = 0;
    left_c--;
    left_n--;

    while (left_c <= left_n && left_c >0 && left_n > 0) {
        int next_ind = n - left_n;
        // std::cout << n << " " << c << " " << interval << " " << left_n << " " << left_c <<" " << curr_ind << " " << next_ind << std::endl;
        if (a[next_ind]-a[curr_ind] >= interval) {
            curr_ind = next_ind;
            left_c--;
        }
        left_n--;
    }
    
    if (left_c == 0) {
        return 1;
    } else {
        return 0;
    }
}

// solution in [l, r]
int find_solution(int *a, int n, int c, long l, long r) {
    int temp_l = l;
    int temp_r = r;

    while (temp_l < temp_r) {
        int temp_solution = (temp_l + temp_r)/2;
        int is_temp_solution_validated = try_solution(a, n, c, temp_solution); 
        if (is_temp_solution_validated) {
            temp_l = temp_solution;
        } else {
            temp_r = temp_solution - 1;
        }
    }

    return temp_l;
}

int main() {
    int t;
    std::cin >> t;

    int a[100000];

    while (t--) {
        int n, c;
        std::cin >> n >> c;

        for (int i=0; i<n; i++) {
            std::cin >> a[i];
        }

        std::sort(a, a+n);

        std::cout << find_solution(a, n, c, 0, 1000000000) << std::endl;
    }
}