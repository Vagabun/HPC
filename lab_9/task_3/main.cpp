#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>

struct cell {
    char data;
    int status;
    std::vector< std::pair<int, int> > adj_list;
};

void bfs(std::vector< std::vector<cell> > &obj, int i, int j) {
    std::queue< std::pair<int, int> > q;
    obj[i][j].status = 1;
    q.emplace(i, j);
    while (!q.empty()) {
        std::pair<int, int> n = q.front();
        q.pop();
        auto temp = obj[n.first][n.second];
        for (auto it = std::begin(temp.adj_list); it != std::end(temp.adj_list); ++it) {
            if (obj[it->first][it->second].status == 0 && obj[it->first][it->second].data == '#') {
                obj[it->first][it->second].status = 1;
                q.emplace(it->first, it->second);
            }
        }
    }
}

int main() {

    unsigned int N, M;
    std::ifstream in("input.txt");

    in >> N >> M;
    std::vector<std::vector<cell> > field(N + 2, std::vector<cell>(M + 2));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (i == 0 || i == 6 || j == 0 || j == 11)
                field[i][j].data = '.';
        }
    }


    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= 10; ++j) {
            in >> field[i][j].data;
            field[i][j].status = 0;
            field[i][j].adj_list.emplace_back(i - 1, j);
            field[i][j].adj_list.emplace_back(i + 1, j);
            field[i][j].adj_list.emplace_back(i, j - 1);
            field[i][j].adj_list.emplace_back(i, j + 1);
        }
    }

    int count = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (field[i][j].data == '#' && field[i][j].status == 0) {
                bfs(field, i, j);
                ++count;
            }
        }
    }

    std::cout << count << std::endl;
    in.close();
    return 0;
}
