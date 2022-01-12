template<class T>
T ModPower( T a, T b, T m = mod){
	T result = 1;
	while(b){
		if(b&1)
			result = (result*a)%m;
		b = b>>1;
		a = (a*a)%m;
	}
	return result;
}



