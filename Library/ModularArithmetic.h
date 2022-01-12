struct Mod {
    ll x;
    Mod (ll xx) : x(xx){}
    Mod operator+ (Mod b) {return Mod((x + b.x) % mod);}
    Mod operator- (Mod b) {return Mod((x - b.x + mod) % mod);}
    Mod operator* (Mod b) {return Mod((x * b.x) % mod);} 
    Mod operator/ (Mod b) {return *this * invert(b);}    
    Mod invert(Mod b){
        return ModPower(b.x, (ll) mod - 2, (ll) mod);
    }
    Mod operator^ (ll e){
        if (!e) return Mod(1);
        Mod r = *this ^ (e/2); r = r * r;
        return e&1 ? *this * r : r;
    }
};
