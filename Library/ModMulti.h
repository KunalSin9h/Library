template<class T>
T modmul( T a, T b, T m = MOD){
    T result = 0;
    while(b){
        if(b&1)
            result = (result + a)%m;
        b >>= 1;
        a = (2*a)%m;
    }
    return result;
}
