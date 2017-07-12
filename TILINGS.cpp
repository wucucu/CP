#include<bits/stdc++.h>
using namespace std;
const int d = 10000;

vector<int> a, b, t;
int main() {
    int n;
    cin >> n;
    a.push_back(1);
    a.push_back(1);
    b.push_back(0);
    b.push_back(1);
    t.push_back(0);
    t.push_back(1);
    for (int i = 2; i <= n; i ++) {
        a.push_back((a[i-1]+a[i-2]+b[i-2]+t[i-2]) % d);
        b.push_back((b[i-1] + a[i-1]) % d);
        t.push_back((t[i-1] + a[i-1]) % d);
    }
    cout << a[n] << endl;
    return 0;
}
