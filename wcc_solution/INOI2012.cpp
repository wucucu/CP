// https://www.codechef.com/IOIPRAC/problems/INOI1202

#include <iostream>
#include <set>
#include <vector>

int main() {

    std::multiset<int> m;
    std::vector<int> v;
    int n;
    std::cin >> n;

    for (int i=1; i<=n; i++) {
        int a;
        std::cin >> a;
        m.insert(a+i);
        v.push_back(a);
    }

    std::cout << *m.rbegin();
    for (int k=1; k<n; k++) {
        int a = v[n-k];
        std::multiset<int>::iterator it = m.find(a+n-k+1);
        m.erase(it);
        m.insert(a-k+1);
        std::cout << " " << *m.rbegin() + k;
    }

    std::cout << std::endl;

    return 0;
}