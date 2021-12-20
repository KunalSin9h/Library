const ll INF = 1LL << 62;
void floydWarshall(vector<vector<ll>> &m){
	int n = sz(m);
	for(int i = 0;i<n; ++i){
		m[i][i] = min(m[i][i], 0LL);
	}
	for(int k = 0;k<n; ++k){
		for(int i = 0;i<n; ++i){
			for(int j = 0;j<n; ++j){
				if(m[i][k] != inf && m[k][j] != inf){ 
					ll newdist = max(m[i][k] + m[k][j], -INF);
					m[i][j] = min(m[i][j], newdist);
				} 
			}
		}
	}
	for(int k = 0;k<n; ++k){
		if(m[k][k] < 0){
			for(int i = 0;i<n; ++i){
				for(int j = 0;j<n; ++j){
					if(m[i][k] != INF && m[k][j] != INF)m[i][j] = -INF;
				}
			}
		}
	}
}


