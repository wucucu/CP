// http://wcipeg.com/problem/ioi0011

#include <iostream>

int a[3][5001];
char s[5001];

int main() {
    int len;
    std::cin >> len;

    for (int i=0;i<len;i++) std::cin >> s[i];
    for (int i=0;i<len;i++) {a[0][i]=0; a[1][i]=0; a[2][i]=0;}

    for (int i=0;i<len;i++) a[1][i] = 0;
    for (int i=0;i+1<len;i++) a[2][i] = s[i]!=s[i+1];


    for (int l=3;l<=len;l++) {
        for (int i=0;i+l-1<len;i++) {
            a[l%3][i] = s[i]==s[i+l-1] ? a[(l-2)%3][i+1] : std::min(a[(l-1)%3][i+1]+1,a[(l-1)%3][i]+1);
        }

    }
    std::cout << a[len%3][0] << std::endl;

    return 0;
}