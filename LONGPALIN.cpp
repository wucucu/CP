#include<bits/stdc++.h>
using namespace std;

vector<char> s;
vector<int> p;

int main() {
    int n;
    cin >> n;
    s.push_back('#');
    string str;
    cin >> str;
    int l = str.length();
    for (int i = 0; i < l; i++) {
         s.push_back(str[i]);
         s.push_back('#');
    }
    s.push_back('?');

    p.push_back(1);
    int mx = 0, id = 0;
    for (int i = 1; i <= 2*n; i++) {
        int q = mx > i ? min(p[2*id-i], mx-i) : 1;
        while (s[i+q] == s[i-q])
            q++;
        if (i + q > mx) {
            mx = i + q;
            id = i;
        }
        p.push_back(q);
    }   

    int i = max_element(p.begin(), p.end()) - p.begin();
    cout << p[i] - 1 << endl;
    for (int j = i-p[i]+1; j < i+p[i]; j++) 
        if (s[j] != '#') cout << s[j];
    cout << endl;
    return 0;
}
