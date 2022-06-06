// Point update and (Range/Point query)

struct Fenwick{
    std::vector<int> T;
    int N;
    Fenwick(int n):N{n}{T.assign(N, 0);}
    Fenwick(std::vector<int> &A): Fenwick((int) A.size()){
        for(int i = 0; i < N; ++i) add(i, A[i]);
    }
    void add(int i, int x){
        assert(i < N);
        for(; i < N; i = (i|(i + 1))) T[i] += x;
    }
    int sum(int r){
        assert(r < N);
        int res = 0;
        for(; r >= 0; r = (r&(r+1)) - 1) res += T[r];
        return res;
    }
    int sum(int l, int r){
        return sum(r) - sum(l-1);
    }
    int get_element(int i){
        return sum(i, i);
    }
};

// 2D -Point update and (Range/Point query)

struct Fenwick2D{
    std::vector<std::vector<int>> T;
    int N, M;
    Fenwick2D(int r, int c): N{r}, M{c}{
        T.resize(N);
        for(int i = 0;i<N; ++i)T[i].resize(M, 0);
    }
    Fenwick2D(std::vector<std::vector<int>> &A): Fenwick2D((int)A.size(), (int)A[0].size()){
        for(int i = 0;i<N; ++i) for(int j = 0;j<M; ++j)  add(i, j, A[i][j]);
    }
    void add(int r, int c, int x){
        assert(r < N && c < M);
        for(int i = r; i < N; i = (i | (i+1))) for(int j = c; j < N; j = (j|(j+1))) T[i][j] += x;
    }
    int sum(int r, int c){
        assert(r < N && c < M);
        int res = 0;
        for(int i = r; i >= 0; i = (i&(i+1)) - 1)for(int j = c; j >= 0; j=(j&(j+1)) - 1) res += T[i][j];
        return res;
    }
    int sum(int r1, int c1, int r2, int c2){
        return sum(r2, c2) - sum(r1-1, c2) - sum(r2, c1-1) + sum(r1-1, c1-1);
    }
    int get_element(int r, int c){
        return sum(r, c, r, c);
    }
};

// Range Update and Point Query

struct Fenwick{
    // assume indices are 0-based
    std::vector<int> T;
    int N;
    Fenwick(int n):N{n+1}{T.assign(N, 0);}
    Fenwick(std::vector<int> &A): Fenwick((int) A.size()){
        for(int i = 0; i < N-1; ++i) point_update(i, A[i]);
    }
    void update(int i, int x){ // Not Point Update
        for(++i; i < N; i += (i&(-i))) T.at(i) += x;
    }
    void range_update(int l, int r, int x){
        update(l, x);
        update(r+1, -x);
    }
    void point_update(int i, int x){
        range_update(i, i, x);
    }
    int point_query(int i){
        int res = 0;
        for(++i; i > 0; i -= (i&(-i))) res += T.at(i);
        return res;
    }
};

// Range update and Range/Point query

struct Fenwick{
    // assuming indices are 0-based
    std::vector<int> T1; /* Normal range update/point query tree (T1)*/
    std::vector<int> T2; /*Tree for Fixing Errors (T2)*/
    int N;
    Fenwick(int n) : N{n+1}{T1.assign(N, 0);T2.assign(N, 0);};
    Fenwick(std::vector<int> &A) : Fenwick((int)A.size()){
        for(int i = 0;i<N-1; ++i) point_update(i, A[i]);
    }
    void update(std::vector<int> &T, int i, int x){ // not point update
        for(++i; i < N; i += (i&(-i))) T.at(i) += x;
    }
    void range_update(int l, int r, int x){
        // Normal Range Update Point Query Tree (T1)
        update(T1, l, x);
        update(T1, r+1, -x);
        // Adding fix
        update(T2, l, x*(l-1));
        update(T2, r+1, -x*r); // simplified of : -x*(l-1) - (r-l+1)*x
    }
    void point_update(int i, int x){
        range_update(i, i, x);
    }
    int point_query(std::vector<int> &T, int i){
        int res = 0;
        for(++i; i > 0; i -= (i&(-i)))res += T.at(i);;
        return res;
    }
    int prefix_sum(int i){
        // i is 0-Based indexing that's why we need to add 1
        return (point_query(T1, i)*(i + 1) - point_query(T2, i)); // Error - Fix = Ans
    }
    int range_query(int l, int r){
        return prefix_sum(r) - prefix_sum(l-1);
    }
    int get_element(int i){
        return range_query(i, i);
    }
};

// min element [0, r] 
struct FenwickMin{
    std::vector<int> T;
    int N;
    const int inf = int(2e9);
    FenwickMin(int n):N{n}{T.assign(N, inf);}
    FenwickMin(std::vector<int> &A): FenwickMin((int)A.size()){
        for(int i = 0;i<N; ++i) update(i, A[i]);
    }
    void update(int i, int x){
        assert(i < N);
        for(; i<N; i = (i|(i+1))) T[i] = std::min(T[i], x);
    }
    int getmin(int r){
        assert(r < N);
        int res = inf;
        for(; r >= 0; r = (r&(r+1))-1) res = std::min(res, T[r]);
        return res;
    }
};

// max element [0, r]
struct FenwickMax{
    std::vector<int> T;
    int N;
    FenwickMax(int n):N{n}{T.assign(N, -1);}
    FenwickMax(std::vector<int> &A): FenwickMax((int)A.size()){
        for(int i = 0;i<N; ++i) update(i, A[i]);
    }
    void update(int i, int x){
        assert(i < N);
        for(; i<N; i = (i|(i+1))) T[i] = std::max(T[i], x);
    }
    int getmax(int r){
        assert(r < N);
        int res = -1;
        for(; r >= 0; r = (r&(r+1))-1) res = std::max(res, T[r]);
        return res;
    }
};
