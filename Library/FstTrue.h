template<class T, class U>
T fstTrue(T lo, T hi, U fun){
	++hi;assert(lo <= hi);
	while(lo < hi){
		T mid = lo + ((hi-lo)>>1);
		fun(mid)?hi = mid:lo = mid + 1;
	}
	return lo;	
}
