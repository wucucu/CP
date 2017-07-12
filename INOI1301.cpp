#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int b[1000010];
int c[1000010];

int n, k;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    b[1] = a[1];
    b[2] = a[1] + a[2];
    for (int i = 3; i <= n; i++) {
        b[i] = max(b[i-1], b[i-2]) + a[i];
    }
    
    c[k] = 0;
    c[k+1] = a[k+1];
    for (int i = k+2; i <= n; i++) {
        c[i] = max(c[i-1], c[i-2]) + a[i]; 
    }

    int mx = -2000000000;
    for (int i = k; i <= n; i++) {
        mx = max(mx, b[i] + c[i] - a[i]);
    }
    cout << mx << endl;
    return 0;
}
