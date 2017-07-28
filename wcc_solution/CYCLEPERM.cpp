// http://opc.iarcs.org.in/index.php/problems/CYCLEPERM

#include <iostream>
#include <vector>

int f[1000];

int main() {
    int n;
    std::cin >> n;

    std::vector<int> v;
    for (int i=0; i<n; i++) {
        int a;
        std::cin >> a;
        v.push_back(a);
        f[i] = 1;
    }

    std::vector<std::vector<int> > r;

    int s_ind = 0;

    while (s_ind < n) {
        if (f[s_ind]) {
            std::vector<int> t;
            int t_ind = s_ind;
            f[t_ind] = 0;
            t.push_back(t_ind + 1);
            t_ind = v[t_ind] - 1;
            while (t_ind != s_ind) {
                f[t_ind] = 0;
                t.push_back(t_ind + 1);
                t_ind = v[t_ind] - 1;
            }
            t.push_back(t_ind + 1);
            r.push_back(t);
        } else {
            s_ind++;
        }
    }

    std::cout << r.size() << std::endl;
    for (std::vector<std::vector<int> >::iterator it=r.begin(); it !=r.end(); it++) {
        std::vector<int> t = *it;
        std::cout << *t.begin();
        for(std::vector<int>::iterator jt=t.begin()+1; jt != t.end(); jt++) {
            std::cout << " " << *jt;
        }
        std::cout << std::endl;
    }

    return 0;
}