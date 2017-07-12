#include<bits/stdc++.h>
using namespace std;

vector<int> v;
stack<int> s;
int mx;

void print_st(stack<int> s) {
    stack<int> v = s;
    cout << "-----" << endl;
    while (!v.empty()) {
        cout << v.top() << " ";
        v.pop();
    }
    cout << endl;
}

int main() {
    int n;
    int start=0, st=0;
    int nsend=0, mxnst = 0;
    int cnt=0;
    cin >> n;
    int len=0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            if (s.empty()) {
                st = i;
            }
            s.push(t);
            cnt ++;
            len ++;
            if ((int)s.size() > mxnst) {
                mxnst = (int)s.size();
                nsend = i;
            }
        } else {
            s.pop();
            cnt--;
            len ++;
            if (s.empty()) {
                if (len > mx) {
                    mx = len;
                    start = st;
                }
                len = 0;
            }
        }
    }
    printf("%d %d %d %d\n", mxnst, nsend+1, mx, start+1);
    return 0;
}
