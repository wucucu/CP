// https://www.codechef.com/ZCOPRAC/problems/ZCO12001

#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int max_depth = 0;
    int first_deepest_ind = 0;
    int longest_sequence_length = 0;
    int longest_sequence_begin_ind = 0;
    int current_sequence_length = 0;
    int current_sequence_begin_ind = 0;

    int current_depth = 0;

    for (int ind=1; ind<=n; ind++) {
        int current_parenthesis;
        int diff_depth;
        std::cin >> current_parenthesis;
        diff_depth = (current_parenthesis == 1) ? 1 : -1;
        current_depth += diff_depth;

        if (current_depth > max_depth) {
            max_depth = current_depth;
            first_deepest_ind = ind;
        }

        if (current_depth==1 && diff_depth==1) {
            current_sequence_length = 0;
            current_sequence_begin_ind = ind;
        }
        current_sequence_length += 1;
        if (current_sequence_length > longest_sequence_length) {
            longest_sequence_length = current_sequence_length;
            longest_sequence_begin_ind = current_sequence_begin_ind;
        }
    }

    std::cout << max_depth << " " 
              << first_deepest_ind << " "
              << longest_sequence_length << " " 
              << longest_sequence_begin_ind << std::endl;
}