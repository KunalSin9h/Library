template<class T, class U>
T lstTrue(T lo, T hi, U fun){
	--lo;assert(lo <= hi);
	while(lo < hi){
		T mid = lo + ((hi-lo + 1)>>1);
		fun(mid)? lo = mid:hi = mid - 1;
	}
	return lo;
}

