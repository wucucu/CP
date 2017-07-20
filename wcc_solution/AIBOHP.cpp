// http://www.spoj.com/problems/AIBOHP/

#include <iostream>
#include <algorithm>
#include <string>

int a[6100][6100];

int main() {
    int t;
    std::cin >> t;

    std::string s;
    while (t--) {
        for (int i=0;i<6100;i++) for (int j=0;j<6100;j++) a[i][j]=0;
        std::cin >> s;
        int len = s.length();
        for (int l=2;l<=len;l++) {
            for (int i=0;i+l-1<len;i++) {
                int j = i+l-1;
                a[i][j] = s[i]==s[j] ? a[i+1][j-1] : std::min(a[i+1][j]+1,a[i][j-1]+1);
            }
        }
        std::cout << a[0][len-1] << std::endl;
    }

    return 0;
}