// http://www.spoj.com/problems/RENT/
// g++ -std=c++11 rent.cpp

// The statement says otherwise, I know, but you can't start a rent at the same time you end the previous one. 
// The statement is incorrect.

#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>


typedef std::tuple<int, int, int, int> mytuple;
 
bool mycompare (const mytuple &lhs, const mytuple &rhs){
  return (std::get<0>(lhs) < std::get<0>(rhs)) || (std::get<0>(lhs) == std::get<0>(rhs) && std::get<1>(lhs) < std::get<1>(rhs));
}
int main() {
    int tt;
    std::cin >> tt;

    int a, b, c;
    int n;

    std::vector<mytuple> v;

    while (tt--) {
        std::cin >> n;
        v.clear();
        for (int i=0; i<n; i++) {
            std::cin >> a >> b >> c;
            v.push_back(std::make_tuple(a, a+b, c, c));
        }

        std::sort(v.begin(), v.end(), mycompare);
        mytuple t = v.back();

        for (auto it=v.begin(); it!=v.end(); it++) {
            for (auto jt=it+1; jt!=v.end(); jt++) {
                // if (std::get<1>(*it) > std::get<0>(*jt)) continue;
                if (std::get<1>(*it) >= std::get<0>(*jt)) continue;
                if (std::get<3>(*it) + std::get<2>(*jt) > std::get<3>(*jt)) std::get<3>(*jt) = std::get<3>(*it) + std::get<2>(*jt);
            }
        }
        
        int m = 0;
        for (auto it=v.begin(); it!=v.end(); it++) {
            if (m < std::get<3>(*it)) m = std::get<3>(*it);
        }

        std::cout << m << std::endl;
    }

    return 0;
}