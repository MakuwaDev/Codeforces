#include <iostream>
#include <tuple>

constexpr long long MOD = 998244353;

static inline long long power_modulo_fast(long long a, long long pow)noexcept
{
	long long i;
	long long result = 1;
	long long x = a % MOD;
	for (i = 1; i <= pow; i <<= 1)
	{
		x %= MOD;
		if ((pow & i) != 0)
		{
			result *= x;
			result %= MOD;
		}
		x *= x;
	}
	return result % MOD;
}

static inline long long factorial(long long x)noexcept
{
    long long res = 1;
    for(long long i = 1; i <= x; ++i)
        res = (res * i) % MOD;
    return res;
}

static inline long long newton(long long k, long long n)noexcept
{
    return (factorial(n) * power_modulo_fast((factorial(k) * factorial(n - k)), MOD - 2)) % MOD;
}

std::tuple<long long, long long, long long> solve(long long n)
{
    if(n == 2) return std::make_tuple(1ll, 0ll, 1ll);
    std::tuple<long long, long long, long long> x = solve(n - 2);
    return std::make_tuple(newton(n / 2, n - 1) + std::get<1>(x), newton(n / 2, n - 2) + std::get<0>(x), 1);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    long long n;
    std::cin>>t;
    while(t--)
    {
        std::cin>>n;
        std::tuple<long long, long long, long long> res = solve(n);
        std::cout<<std::get<0>(res) % MOD<<" "<<std::get<1>(res) % MOD<<" "<<std::get<2>(res)<<"\n";
    }
}
