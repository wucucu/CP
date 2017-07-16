// https://www.codechef.com/IOIPRAC/problems/INOI1201

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

bool mycmp(std::pair<int,int> &a, std::pair<int,int> &b) {
    return (a.second>b.second) || ((a.second==b.second) && (a.first<b.first));
}



int main() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int,int> > A;

    for (int i=0; i<N; i++) {
        int x, y, z;
        std::cin >> x >> y >> z;
        A.push_back(std::make_pair(x, y+z));
    }

    std::sort(A.begin(), A.end(), mycmp);

    int curr_end_time=0;
    int first_competition_end_time = 0;
    int last_player_second_competition_end_time = 0;

    for (std::vector<std::pair<int,int> >::iterator it=A.begin(); it!=A.end(); it++) {
        first_competition_end_time += it->first;
        last_player_second_competition_end_time = first_competition_end_time + it->second;
        curr_end_time = std::max(curr_end_time, last_player_second_competition_end_time);
    }

    std::cout << curr_end_time << std::endl;

    return 0;
}