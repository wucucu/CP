#include<bits/stdc++.h>
using namespace std;

template <class T>
void print(T x){
    for (int i = 0; i < 10; i++)
        printf("%5d ", x[i]);
    cout << endl;
}

int a[5010], pos[5010], neg[5010];
int dp[5010];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        pos[i] = INT_MAX;
        neg[i] = INT_MAX;
    }
    pos[0] = 0;
    neg[0] = 0;

    for (int i = 0; i < n; i++) {
        int t;
        if (a[i] > 0) {
            // find the last item in neg that is less than a[i]
            t = lower_bound(neg, neg+i+1, a[i]) - neg - 1;
            dp[i] = t + 1;
            int j = dp[i];
            while (pos[j] > a[i]) {
                pos[j--] = a[i];
            }
        } else {
            t = lower_bound(pos, pos+i+1, -a[i]) - pos - 1;
            dp[i] = t + 1;
            int j = dp[i];
            while (neg[j] > -a[i]) {
                neg[j--] = -a[i];
            }
        }
    }
    cout << *max_element(dp, dp+n) << endl; 
    //int mx = dp[0];
    //for (int i = 1; i < n; i++)
    //    if (dp[i] > mx)
    //        mx = dp[i];
    //cout << mx << endl;
    return 0;
}
