#include<bits/stdc++.h>
using namespace std;

int n;
string str;
int a[5010][3];

int min_insert(string s){
    int l = s.size();
    memset(a, 0, sizeof(a));
    for (int i = 0; i < l; i++)
        a[i][i] = 0;
    for (int g = 1; g < l; g++) {
        for (int i = 0; i + g < l; i++) {
            int j = i + g;
            a[i][g%3] = s[i] == s[j] ? a[i+1][(g+1)%3] : min(a[i+1][(g+2)%3] + 1, a[i][(g+2)%3]+1);
        }
    }
    return a[0][(l-1)%3];
}

int main() {
    cin >> n;
    cin >> str;
    cout << min_insert(str) << endl;
    return 0;
}
