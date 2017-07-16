// http://opc.iarcs.org.in/index.php/problems/AVERAGE

#include <iostream>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    int a[10000];
    for (int i=0; i<N; i++) {
        std::cin >> a[i];
    }

    std::sort(a, a+N);

    int cnt = 0;
    for (int k=0; k<N; k++) {
        int *head=a, *tail=a+N-1;
        int target = *(a+k) * 2;

        while (head != tail) {
            int temp_sum = *head + *tail;
            if (temp_sum > target) {
                tail--;
            } else if (temp_sum < target){
                head++;
            } else {
                cnt++;
                break;
            }
        }
    }

    std::cout << cnt << std::endl;

    return 0;
}