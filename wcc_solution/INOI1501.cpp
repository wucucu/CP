// https://www.codechef.com/IOIPRAC/problems/INOI1501

#include <iostream>
#include <algorithm>
#include <numeric>
#define ll long long
ll a[1000010];
ll b[1000010];
ll dp1[1000010];
ll dp2[1000010];

int main() {
    int N;
    std::cin >> N;

    for (int i=0; i<N; i++) std::cin >> a[i];
    for (int i=0; i<N; i++) std::cin >> b[i];

    if (N==1) {
        std::cout << a[0] << std::endl;
        return 0;
    }
    
    // no wrap cases, max_ssum of sequences(length>=2) end at index_i (1<=index_i<=N-1)
    dp1[1] = a[0] + a[1];
    for (int i=2; i<N; i++) dp1[i] = std::max(dp1[i-1]-a[i-1]+b[i-1]+a[i], a[i-1] + a[i]);

    ll total_sum = std::accumulate(b, b+N, (ll)0);
    // wrap cases, max_ssum(-total_sum of array b) of sequences(length>=2) end at index_i (N-2>=index_i>=0)
    dp2[N-2] = a[N-1] + a[N-2] - b[N-1] - b[N-2] + total_sum;
    for (int i=N-3; i>=0; i--) dp2[i] = std::max(dp2[i+1]-a[i+1]+a[i]-b[i], a[i+1]+a[i]-b[i+1]-b[i]+total_sum);

    ll max_ssum = a[0];

    for (int i=1; i<N; i++) max_ssum = std::max(a[i], max_ssum);
    for (int i=1; i<N; i++) max_ssum = std::max(dp1[i], max_ssum);
    for (int i=0; i<N-1; i++) max_ssum = std::max(dp2[i], max_ssum);

    // for (int i=1; i<N; i++) std::cout << dp1[i] << " ";
    // std::cout << std::endl;
    // for (int i=0; i<N-1; i++) std::cout << dp2[i] << " ";
    // std::cout << std::endl;

    std::cout << max_ssum << std::endl;

    return 0;
}