struct Fenwick{
std::vector<int> T;
int N;
Fenwick(int n):N{n}{T.assign(N, 0);}
Fenwick(std::vector<int> &A): Fenwick((int) A.size()){
    for(int i = 0; i < N; ++i) add(i, A[i]);
}
void add(int i, int x){
    assert(i < N);
    for(; i < N; i = (i | (i + 1))) T[i] += x;
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