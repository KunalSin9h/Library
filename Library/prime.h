vector<int> least_prime_factor;
vector<int> all_primes;
vector<bool> check_prime;

void run_sieve(int max_n){
    least_prime_factor.resize(max_n + 1, 0); 
    check_prime.resize(max_n + 1, true);
    check_prime[0] = check_prime[1] = false;
        
    for(int i = 2; i <= max_n; ++i)
        if(check_prime[i]){
            least_prime_factor[i] = i;
            all_primes.emplace_back(i);
            for(int64_t j = int64_t(i)*i; j <= max_n; j += i)
                if(check_prime[j]){
                    check_prime[j] = false;
                    least_prime_factor[j] = i;
                }
        }
}

vector<pair<int64_t, int>> prime_factorize(int64_t n){
    int64_t sieve_max = int64_t(least_prime_factor.size()) - 1;  
    assert(1 <= n && n <= sieve_max*sieve_max);
    vector<pair<int64_t, int>> result;

    if(n <= sieve_max){
        while(n != 1){
            int64_t p = least_prime_factor[n];
            int expo = 0;
            
            do{
                n /= p;
                expo++;
            } while(n%p == 0);

            result.emplace_back(p, expo);

        }
        return result;
    }

    for(int64_t p : all_primes){
        if(p*p > n)break; 
        if(n%p == 0){
            int expo = 0;
            do{
                n /= p;
                expo++;
            }while(n%p == 0);
            result.emplace_back(p, expo);
        }
    }
         
    if(n > 1) result.emplace_back(n, 1); 

    return result;
}

constexpr int sieve_max = int(1e6) + 10;
