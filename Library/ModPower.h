template<class T> T ModPower( T a, long long b, T mod){
    a %= mod;
    T result = 1;
    while(b){
        if(b&1)
            result = (result*a)%mod;
        b = b>>1;
        a = (a*a)%mod;
    }
    return result;
}
