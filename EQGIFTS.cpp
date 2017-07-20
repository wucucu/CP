#include<bits/stdc++.h>
using namespace std;

set<int> s;
set<int> p;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (s.empty()){
            s.insert(a-b);
            s.insert(b-a);
            continue;
        }
        for (set<int>::iterator it = s.begin(); it!=s.end(); it++) {
            p.insert(*it + a - b);
            p.insert(*it - a + b);
        }
        s = p;
        p.clear();
    }
    int mn = abs(*s.begin());
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        mn = min(abs(*it), mn);
    }
    cout << mn << endl;
    return 0;
}
