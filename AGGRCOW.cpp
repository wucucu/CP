#include<bits/stdc++.h>
using namespace std;

long long a[100010];
int n, c;

bool check(int x) {
    int j = 0;
    int current = a[j++];
    for (int i = 1; i < c; i++) {
        while (j < n && a[j] < current + x)
            j++;
        if (j == n) 
            return false;
        current = a[j];
    }
    return true;
}

int binary_search() {
    int l = 1;
    int r = a[n-1];
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> n >> c;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a+n);
        cout << binary_search() << endl;
    }
    return 0;
}
