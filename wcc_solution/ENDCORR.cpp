// http://opc.iarcs.org.in/index.php/problems/ENDCORR

#include <iostream>
#include <queue>
#include <functional>

int main() {
    std::priority_queue<int> pq;

    int m, n;
    std::cin >> m >> n;

    while (n>0) {
        int a;
        std::cin >> a;
        if (a!=-1) {
            pq.push(a);
        } else {
            std::cout << pq.top() << std::endl;
            pq.pop();
            n--;
        }
    }
}