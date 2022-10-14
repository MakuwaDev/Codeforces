#include <iostream>
#include <vector>

constexpr long long MAXN = 1e6 + 6;
constexpr long long MOD = 1e9 + 7;

long long pow2[MAXN];

static inline void calcPow2()noexcept
{
    pow2[0] = 1;
    for(long long i = 1; i < MAXN; ++i)
        pow2[i] = (pow2[i - 1] * 2) % MOD;
}

static inline long long power_modulo_fast(long long a, long long pow)noexcept
{
	long long i;
	long long result = 1;
	long long x = a;
	for (i = 1; i <= pow; i <<= 1)
	{
		if ((pow & i) != 0) result = (result * x) % MOD;;
		x = (x * x) % MOD;
	}
	return result;
}

void solve()
{
    long long n;
    std::cin>>n;
    if(n == 1)
    {
        std::cout<<"1\n";
        return;
    }
    std::vector <long long> res(n + 1, 0), sufsum(n + 1, 0);
    sufsum[n] = res[n] = power_modulo_fast(pow2[(n - 1) / 2], MOD - 2);
    for (int i = n - 1; i > 1; i--)
    {
        res[i] = power_modulo_fast(pow2[(i + 1) / 2], MOD - 2);
        if (2 * i <= n) res[i] = res[i] * (1 - sufsum[i * 2] + MOD) % MOD;
        sufsum[i] = (sufsum[i + 1] + res[i]) % MOD;
    }
    for (int i = 1; i <= n; i++)
        std::cout << res[i] << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    calcPow2();
    long long t;
    std::cin>>t;
    while(t--)
        solve();

}
