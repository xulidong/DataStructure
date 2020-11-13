// 并查集
#ifndef UNION_FIND_SET_H
#define UNION_FIND_SET_H

#include <vector>

using namespace std;

class UnionFind {
public:
    UnionFind(vector<vector<int>>& grid) {
        count = 0;
        int row = grid.size();
        int col = grid[0].size();
        count = row * col;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                parent.push_back(i * col + j);
                rank.push_back(1);
            }
        }
    }

    int find(int i) {
        if (parent[i] != i) {
            // 路径压缩
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            // 按秩合并（小树合并到大树）
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;

            if (rank[rootx] == rank[rooty]) {
                rank[rootx] += 1;
            }
            --count;
        }
    }

    int getCount() const {
        return count;
    }

private:
    vector<int> parent;// 父节点
    vector<int> rank;// 每个集合的深度
    int count; // 集合数量
};

#endif