// http://www.spoj.com/problems/LVADER/

#include <iostream>
#include <algorithm>

#define ll long long

ll m = 1000000007;
ll fact[200010];
ll ifact[200010];

ll power_mod(ll a, ll p) {
    ll x = a%m;
    if (p==1) return x;
    if (p%2 == 1) {
        return (x%m * power_mod((x*x)%m, p/2))%m;
    } else {
        return power_mod((x*x)%m, p/2);
    }
}

int main() {

    int tt;
    std::cin >> tt;

    fact[0] = 1;
    ifact[0] = 1;
    for (ll i=1; i<200001; i++) fact[i] = (fact[i-1] * i) % m;
    for (ll i=0; i<200001; i++) ifact[i] = power_mod(fact[i], m-2) % m;

    int t = 0;
    while (t++ < tt) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;

        int x = x2-x1;
        int y = y2-y1;

        int z = std::min(x, y);
        ll r = 1;
        ll s = 0;

        for (int k=0; k<=z; k++) {
            r = 1;
            r = (r * fact[x+y-k]) % m;
            r = (r * ifact[x-k]) % m;
            r = (r * ifact[y-k]) % m;
            r = (r * ifact[k]) % m;
            s = (s + r) % m;
        }

        std::cout << "Case " << t << ": "<< s << std::endl;
    }

    return 0;
}