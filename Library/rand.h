std::mt19937 rng((unsigned int) std::chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) std::uniform_int_distribution<unsigned int>(a, b)(rng)

std::mt19937_64 rng_64((unsigned long long) std::chrono::steady_clock::now().time_since_epoch().count());
#define uid_64(a, b) std::uniform_int_distribution<unsigned long long>(a, b)(rng_64)
