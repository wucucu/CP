#include<bits/stdc++.h>
using namespace std;

bool my_cmp(pair<int, int> x, pair<int, int> y) {
    return (x.first + max(x.second, y.first + y.second) < 
            y.first + max(y.second, x.first + x.second));
}

vector<pair<int, int> > s;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        s.push_back(make_pair(a, b+c));
    }
    sort(s.begin(), s.end(), my_cmp);
    long long ans = 0;
    long long start = 0;
    for (int i = 0; i < n; i++) {
        long long f = start + s[i].first + s[i].second;
        ans = max(ans, f);
        start += s[i].first;
    }
    cout << ans << endl;
    return 0;
}
