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