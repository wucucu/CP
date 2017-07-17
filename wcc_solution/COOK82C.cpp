// https://www.codechef.com/problems/COOK82C

#include <iostream>
#include <algorithm>
#include <queue>

int main() {
    int N, M;
    std::cin >> N >> M;

    long long a[1000000];

    for (int i=0; i<N; i++) {
        std::cin >> a[i];
    }

    std::sort(a, a+N, std::greater<long long>());

    std::queue<long long> q1, q2;

    for (int i=0; i<N; i++) {
        q1.push(a[i]);
    }

    int step=0;
    for (int i=0; i<M; i++) { 
        int S;
        std::cin >> S;
        long long x0;
        while (step < S) {
            step++;
            long long x1 = q1.empty() ? 0 : q1.front();
            long long x2 = q2.empty() ? 0 : q2.front();
            if (x1 > x2) {
                q1.pop();
                x0 = x1;
            } else {
                q2.pop();
                x0 = x2;
            }
            q2.push(x0/2);
        }
        std::cout << x0 << std::endl;
    }

    return 0;
}