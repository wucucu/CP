#include<bits/stdc++.h>
using namespace std;

queue<long long> p,q;
vector<long long> v;
vector<long long> arr;

template<class T>
void print(T x) {
    cout << "--------" << endl;
    for (auto it = x.begin(); it!=x.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    for (auto it = arr.rbegin(); it != arr.rend(); it++) {
        p.push(*it);
    }

    for (int i = 0; i < 63000001; i++) {
        if (q.empty()) {
            if (p.empty()) break;
            long long mx = p.front();
            p.pop();
            v.push_back(mx);
            if (mx/2 != 0) q.push(mx/2);
        } else if (p.empty()){
            long long mx = q.front();
            q.pop();
            v.push_back(mx);
            if (mx/2 != 0) q.push(mx/2);
        } else {
            long long mx;
            if (p.front() > q.front()) {
                mx = p.front();
                p.pop();
                if (mx/2!=0) q.push(mx/2);
            } else {
                mx = q.front();
                q.pop();
                if (mx/2!=0) q.push(mx/2);
            }
            v.push_back(mx);
        }
    }
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        cout << v[a-1] << '\n';
    }
    cout << endl;
    return 0;
}
