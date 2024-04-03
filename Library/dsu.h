struct Dsu {
private:
    std::vector<int> parent, rank;
public:
    std::vector<int> size;

    Dsu(int n) {
        parent.resize(n, 0);
        rank.resize(n, 0);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) { parent[i] = i; }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        else return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)return;
        if (rank[x] < rank[y]) {
            parent[x] = y;
            size[y] += size[x];
        } else {
            parent[y] = x;
            size[x] += size[y];
            if (rank[x] == rank[y])rank[x]++;
        }
    }

    bool same(int x, int y) {
        return (find(x) == find(y));
    }
};
