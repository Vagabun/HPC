#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>

struct cell {
    char data;
    int status, parent, root;
};

void bfs(std::vector< std::vector<cell> > &obj, int i, int j) {

    std::queue< std::pair<int, int> > q;
    obj[i][j].status = 1;
    q.push(std::make_pair(i, j));
    while (!q.empty()) {
//        std::pair<int, int> temp = q.front();
        int k = q.front().first;
        int l = q.front().second;
        q.pop();
        if (obj[k-1][l].data == '#' || obj[k+1][l].data == '#' || obj[k][l-1].data == '#' || obj[k][l+1].data == '#') {

        }
    }
//    std::pair<int, int>;
//    obj[i][j].status = 1;
//    q.push(std::make_pair(i, j));
//    while (!q.empty()) {
//        for (int k = i; k < obj[i].size(); ++k) {
//            if (obj[i][k].data == '#' && obj[i][k].status == 0) {
//                if ((obj[i][k+1].data == '#' && obj[i][k+1].status == 0) || (obj[i+1][k].data == '#' && obj[i+1][k].status == 0)) {
//
//                }
//            }
//        }
//    }

    //obj[i][j].root =
}

int main() {
//    std::priority_queue
//    std::vector< std::vector<cell> > field;
//    std::ifstream in("input.txt");
//
//    unsigned int N, M;
//
//    cell buf = cell();
//    in >> N >> M;
//    field.resize(N);
//    for (auto i : field)
//        i.resize(M);


//    for (int i = 0; i < N; ++i) {
//        std::vector<cell> temp;
//        for (int j = 0; j < M; ++j) {
//            in >> buf.data;
//            buf.status = 0;
//            buf.parent = buf.root = -1;
//            temp.push_back(buf);
//        }
//        field.push_back(temp);
//    }

    std::vector < std::vector<cell> > test(7, std::vector<cell>(12));
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
        }
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}