#include<bits/stdc++.h>
using namespace std;

multiset<int> mxs, mns;
int ans;

int move(multiset<int> mx, multiset<int> mn, int k) {
    int s = *mx.rbegin() + *mn.rbegin();
    for (int i = 0; i < k; i++) {
        int a = *mx.begin();
        int b = *mn.rbegin();
        mx.erase(mx.begin());
        mx.insert(b);
        mn.erase(--mn.end());
        mn.insert(a);
        s = min(s, *mx.rbegin() + *mn.rbegin());
    }
    return s;
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        mxs.insert(t);
    }
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        mns.insert(t);
    }
    if (*mxs.rbegin() < *mns.rbegin())
        swap(mxs, mns);

    int ans = move(mxs, mns, k);
    int a = *mxs.rbegin();
    int b = *mns.begin();
    mxs.erase(--mxs.end());
    mxs.insert(b);
    mns.erase(mns.begin());
    mns.insert(a);
    swap(mxs, mns);
    ans = min(ans, move(mxs, mns, k-1));
    cout << ans << endl;
    return 0;
}
