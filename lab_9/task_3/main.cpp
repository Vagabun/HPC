#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>

struct cell {
    char data;
    int status, parent, root;
    std::vector< std::pair<int, int> > adj_list;
};

void bfs(std::vector< std::vector<cell> > &obj, int i, int j) {

    std::queue< std::pair<int, int> > q;
    obj[i][j].status = 1;
    q.emplace(i, j);
    while (!q.empty()) {
        std::pair<int, int> temp = q.front();
        q.pop();
        auto temp_2 = obj[temp.first][temp.second];
        for (auto it = std::begin(temp_2.adj_list); it != std::end(temp_2.adj_list); ++it) {
            if (obj[it->first][it->second].status == 0 && obj[it->first][it->second].data == '#') {
                obj[it->first][it->second].status = 1;
                q.emplace(it->first, it->second);
            }
        }
    }
}

int main() {

    std::vector<std::vector<cell> > test(7, std::vector<cell>(12));
    int l = 7, g = 12;
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < g; ++j) {
            if (i == 0 || i == 6 || j == 0 || j == 11)
                test[i][j].data = '.';
        }
    }

    std::ifstream in("input.txt");
    for (int k = 1; k <= 5; ++k) {
        for (int i = 1; i <= 10; ++i) {
            in >> test[k][i].data;
            test[k][i].status = 0;
            test[k][i].adj_list.emplace_back(k - 1, i);
            test[k][i].adj_list.emplace_back(k + 1, i);
            test[k][i].adj_list.emplace_back(k, i - 1);
            test[k][i].adj_list.emplace_back(k, i + 1);
        }
    }

    int count = 0;
    for (int k = 1; k <= 5; ++k) {
        for (int i = 1; i <= 10; ++i) {
            if (test[k][i].data == '#' && test[k][i].status == 0) {
                bfs(test, k, i);
                ++count;
            }
        }
    }


    std::cout << count << std::endl;
    return 0;
}
