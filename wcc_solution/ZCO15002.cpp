// https://www.codechef.com/ZCOPRAC/problems/ZCO15002

#include <iostream>
#include <algorithm>

// find index in [left, right)
int find_ind(int *a, int left, int right, int target) {

    if (left>=right || *(a+right-1) < target) return -1;

    if ( *(a+left) >= target ) return left;

    int mi = (left + right - 1) / 2;

    if (*(a+mi) >= target) {
        return find_ind(a, left, mi+1, target);
    } else {
        return find_ind(a, mi+1, right, target);
    }

}

int main() {
    int N, K;
    std::cin >> N >> K;

    int a[65000];

    for (int i=0; i<N; i++) {
        std::cin >> a[i];
    }

    std::sort(a, a+N);

    int slow = 0;
    int fast = 0;
    // int *fast_pointer;
    int cnt = 0;

    while (slow<N) {
        fast = std::max(slow+1, fast);
        fast = find_ind(a, fast, N, a[slow]+K);
        // fast_pointer = std::lower_bound(a, a+N, a[slow]+K);
        if (fast == -1) {
            break;
        } else {
            cnt += (N - fast);
        }
        // if (fast_pointer == -1) {
        //     break;
        // } else {
        //     cnt += (a + N - fast_pointer);
        // }
        slow++;
    }

    std::cout << cnt << std::endl;

    return 0;
}