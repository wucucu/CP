#include<bits/stdc++.h>
using namespace std;

vector<int> a;
vector<int> b;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());

    int ans = 0;
    if (a[0] == a[1]) ans ++;
    if (a[n-1] == a[n-2]) ans ++;
    for (int i = 1; i < n-1; i++) {
        int k = a[i]*2;
        if ((a[i] == a[i-1]) || (a[i] == a[i+1])) {
            ans ++;
            continue;
        } 
        int l = i - 1;
        int r = i + 1;
        while (l >= 0 && r <= n-1) {
            if (a[l] + a[r] == k) {
                ans ++;
                break;
            } else {
                if (a[l] + a[r] > k) {
                    l --;
                } else {
                    r ++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
