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
    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }
    if (n == 2) {
        cout << max(a[0], a[1]) << endl;
        return 0;
    }
    if (n == 3) {
        cout << max(max(a[0], a[1]), a[2]) << endl;
        cout << *max_element(a.begin(), a.begin()+3) << endl;
        return 0;
    }
    for (int i = 0; i < 3; i ++) {
        b.push_back(a[i]);
    }
    for (int i = 3; i < n; i++) {
        b.push_back(*min_element(b.begin()+i-3, b.begin()+i) + a[i]);
    }
    cout << *min_element(b.rbegin(), b.rbegin()+3) << endl; 
    return 0;
}
