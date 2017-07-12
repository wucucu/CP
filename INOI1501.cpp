#include<bits/stdc++.h>
using namespace std;

vector<long long> a, s;
vector<long long> f, b;

template <class T>
void print(T a){
    cout << "----" << endl;
    for (auto it = a.begin(); it!=a.end(); it++)
        cout << *it << " ";
    cout << endl;
    cout << "----" << endl;
}

int main() {
    int n;
    cin >> n;
    long long u = -LLONG_MAX;
    long long v = -LLONG_MAX;
    long long w = -LLONG_MAX;
    a.push_back(0);
    for (int i = 0; i < n; i++) {
        long long k;
        cin >> k;
        u = max(u, k);
        a.push_back(k);
    }

    s.push_back(0);
    for (int i = 0; i < n; i++) {
        long long k;
        cin >> k;
        s.push_back(s[i] + k);
    }

    f.push_back(a[1]-s[1]);
    for (int i = 2; i <= n; i++) {
        f.push_back(max(f[i-2], a[i]-s[i]));
    }
    
    for (int j = 2; j <= n; j++) {
        v = max(v, a[j]+s[j-1]+f[j-2]);
    }

    b.push_back(a[n]-s[n]);
    for (int i = n-1; i > 0; i--) {
        b.push_back(max(*(--b.end()), a[i]-s[i]));
    }
    
    for (int j = 1; j < n-1; j++) {
        w = max(w, a[j]+s[j-1]+s[n]+b[n-j-1]);
    }
    
    cout << max(max(w, v), u) << endl;
    
    return 0;
}
