#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    while (k--) {
        vector<int> a;
        for (int i = 0; i < n; i++) {
            int b;
            cin >> b;
            a.push_back(b);
        }
        next_permutation(a.begin(), a.end());
        cout << a[0];
        for (int i = 1; i < n; i++)
            cout << " " << a[i];
        cout << endl;
    }
    return 0;
}
