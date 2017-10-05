// http://opc.iarcs.org.in/index.php/problems/GREATESC

#include <iostream>
#include <algorithm>

#define INF 9999

int dist[3510][3510];

// void print_dist(int N) {
//     for (int i=0; i < N; i++) {
//         for (int j=0; j < N; j++) {
//             std::cout << dist[i][j] << " ";
//         }
//         std::cout << std::endl;
//     }
// }

int main() {

    int N, M;
    std::cin >> N >> M;

    for (int i=0; i < N; i++) {
        for (int j=0; j < N; j++) {
            if (i==j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = INF;
            }
        }
    }

    // print_dist(N);

    for (int i=0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        dist[a-1][b-1] = 1;
        dist[b-1][a-1] = 1;
    }

    // print_dist(N);

    for (int k=0; k < N; k++) {
        for (int i=0; i < N; i++) {
            for (int j=0; j < N; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // print_dist(N);

    int S, T;
    std::cin >> S >> T;

    int r;
    r = dist[S-1][T-1] < INF ? dist[S-1][T-1] : 0;

    std::cout << r << std::endl;

    return 0;
}