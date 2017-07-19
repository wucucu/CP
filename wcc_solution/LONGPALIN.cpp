// http://opc.iarcs.org.in/index.php/problems/LONGPALIN

#include <iostream>
#include <algorithm>

char s[5000];
bool is_palin[5000][5000];

int main() {
    int n;
    std::cin >> n;
    for (int i; i<n; i++) std::cin >> s[i];

    int max_len = 0;
    int mark_ind = 0;

    for (int end_ind=0; end_ind<n; end_ind++) {
        for (int begin_ind=end_ind; begin_ind>=0; begin_ind--) {
            is_palin[begin_ind][end_ind] = false;
            if (s[begin_ind]==s[end_ind]&&(end_ind-begin_ind<=1 || is_palin[begin_ind+1][end_ind-1])) {
                is_palin[begin_ind][end_ind] = true;
                if (end_ind-begin_ind+1>max_len) {
                    max_len = end_ind-begin_ind+1;
                    mark_ind = begin_ind;
                }
            }
        }
    }

    std::cout << max_len << std::endl;
    for (int i=0; i<max_len; i++) std::cout << s[mark_ind+i];
    std::cout << std::endl;

    return 0;
}