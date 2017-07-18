#include<bits/stdc++.h>
using namespace std;

string str;
int a[6200][6200];

int min_insert(string s){
    int l = s.size();
    memset(a, 0, sizeof(a));
    for (int i = 0; i < l; i++)
        a[i][i] = 0;
    for (int g = 1; g < l; g++) {
        for (int i = 0; i + g < l; i++) {
            int j = i + g;
            a[i][j] = s[i] == s[j] ? a[i+1][j-1] : min(a[i+1][j] + 1, a[i][j-1]+1);
        }
    }
    return a[0][l-1];
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        cin >> str;
        cout << min_insert(str) << endl;
    }
    return 0;
}
