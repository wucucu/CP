// http://www.spoj.com/problems/AGGRCOW/

#include <iostream>
#include <algorithm>

int try_solution(int *a, int n, int c, int interval) {
    bool valid =  true;
    int left_c = c;
    int left_n = n;

    if (c==0 && c>n) return false;

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
    if (l > r) return 0;
    if (l == r) return try_solution(a, n, c, l) ? l : 0;
    int temp_solution = (l + r)/2;
    // std::cout << l << " " << temp_solution << " " << r << std::endl;
    int is_temp_solution_validated = try_solution(a, n, c, temp_solution);
    if (is_temp_solution_validated) {
        return std::max(temp_solution, find_solution(a, n, c, temp_solution+1, r));
    } else {
        return find_solution(a, n, c, l, temp_solution-1);
    }
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