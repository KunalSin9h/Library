struct UF {
private:
    vector<int> parent, rank;
public:
    UF(int n){ 
        parent.resize(n, 0);
        rank.resize(n, 0);
        for(int i = 0;i<n; ++i){parent[i] = i;}
    }
    int find(int x){
        if(parent[x] == x)return x;
        else return  parent[x] =  find(parent[x]);
    }
    void unite(int x, int y){
        x = find(x), y = find(y);
        if(x == y)return;
        if(rank[x] < rank[y]){
            parent[x] = y;
        }
        else{
            parent[y] = x;
            if(rank[x] == rank[y])rank[x]++;
        }
    }
    bool same(int x, int y){
        return find(x) == find(y);
    } 
};

