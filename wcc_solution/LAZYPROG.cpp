// https://www.spoj.com/problems/LAZYPROG/

#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <queue>

#define ll long long

typedef std::tuple<ll, ll, ll> contract_tuple;

bool deadline_compare (const contract_tuple &lhs, const contract_tuple &rhs) {
    return std::get<2>(lhs) < std::get<2>(rhs);
}

int main() {
    ll tt;
    std::cin >> tt;

    ll a, b, d;
    ll n;

    std::vector<contract_tuple> v;

    while (tt--) {
        std::cin >> n;

        while (n--) {
           std::cin >> a >> b >> d;
            v.push_back(std::make_tuple(a, b, d));
        }

        std::sort(v.begin(), v.end(), deadline_compare);

        ll total_time = 0;
        double total_money = 0;
        std::priority_queue<std::pair<ll, ll>> pq;

        for (auto ct: v) {
            a = std::get<0>(ct);
            b = std::get<1>(ct);
            d = std::get<2>(ct);
            total_time += b;
            pq.push(std::make_pair(a, b));
            if (total_time <= d) continue;

            while (true) {
                auto temp_pair = pq.top();
                pq.pop();

                ll temp_a = std::get<0>(temp_pair);
                ll temp_b = std::get<1>(temp_pair);

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
        printf("%.2f", total_money);
        std::cout << std::endl;
    }
    return 0;
}
