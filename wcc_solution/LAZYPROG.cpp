// https://www.spoj.com/problems/LAZYPROG/

#include <iostream>
#include <algorithm>
#include <tuple>
#include <queue>

#define ll long long


typedef std::tuple<ll, ll, ll> contract_tuple;

bool deadline_compare (const contract_tuple &lhs, const contract_tuple &rhs) {
    return std::get<2>(lhs) < std::get<2>(rhs);
}

int main() {
    int tt;
    std::cin >> tt;

    ll a, b, d;
    ll n;

    contract_tuple contracts[100000];

    while (tt--) {
        std::cin >> n;

        for (ll i = 0; i < n; i++) {
            std::cin >> a >> b >> d;
            contracts[i] = (std::make_tuple(a, b, d));
        }

        std::sort(contracts, contracts + n, deadline_compare);

        long double total_time = 0;
        long double total_money = 0;
        std::priority_queue<std::pair<ll, ll>> pq;

        for (ll i = 0; i < n; i++) {
            contract_tuple ct = contracts[i];
            a = std::get<0>(ct);
            b = std::get<1>(ct);
            d = std::get<2>(ct);
            total_time += b;
            pq.push(std::make_pair(a, b));
            if (total_time <= d) continue;

            while (true) {
                auto temp_pair = pq.top();
                pq.pop();

                int temp_a = std::get<0>(temp_pair);
                int temp_b = std::get<1>(temp_pair);

                if (total_time - temp_b < d) {
                    temp_b -= d;
                    total_money += double(total_time - d) / double(temp_a);
                    total_time = d;
                    pq.push(std::make_pair(temp_a, temp_b));
                    break;
                }
                else {
                    total_money += double(temp_b) / double(temp_a);
                    total_time -= temp_b;
                }
            }
        }
        printf("%.2Lf", total_money);
        std::cout << std::endl;
    }
    return 0;
}
