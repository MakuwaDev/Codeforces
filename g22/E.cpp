#include <iostream>
#include <vector>
#include <functional>

constexpr long long MOD = 998244353;
constexpr long long MAXN = 1e5+5;

std::vector<long long> factorial(MAXN, 1);
std::vector<long long> invfactorial(MAXN, 1);

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

static inline void calculateFactorial()noexcept
{
	for (int i = 1; i < MAXN; ++i)
	{
		factorial[i] = factorial[i - 1] * i % MOD;
		invfactorial[i] = invfactorial[i - 1] * power_modulo_fast(i, MOD - 2) % MOD;
	}
}

static inline long long newton(long long n, long long k)noexcept
{
    return factorial[n] * invfactorial[k] % MOD * invfactorial[n - k] % MOD;
}

void solve()
{
    int n;
    std::cin>>n;
    std::vector<long long> a(n + 1);
    for(int i = 1; i<= n; ++i)
        std::cin>>a[i];

	std::function<long long(int, int)> f = [&](int i, int j) -> long long
	{
		int l = i, r = j;
		while (l <= j && a[l] == 0) ++l;
		while (r >= i && a[r] == 0) --r;
		if (l == j + 1) return power_modulo_fast(2, j - i);
		if (i != l && j != r)
		{
			int x = l - i, y = j - r;
			long long coef = 0;
			for (int k = 0; k <= std::min(x, y); ++k)
				coef = (coef + newton(x, k) * newton(y, k)) % MOD;
			return f(l, r) * coef % MOD;
		}
		i = l, j = r;
		long long ls = a[i], rs = a[j];
		while (ls != rs)
        {
			if (ls < rs) ls += a[++i];
			else rs += a[--j];
        }
		if (i >= j) return 1;
		l = i + 1, r = j - 1;
		while (l <= j && a[l] == 0) ++l;
		while (r >= i && a[r] == 0) --r;
		if (l == j) return power_modulo_fast(2, j - i);
		int x = l - i - 1, y = j - r - 1;
		long long coef = 0;
		for (int k = 0; k <= std::min(x, y) + 1; ++k)
			coef = (coef + newton(x + 1, k) * newton(y + 1, k)) % MOD;
		return f(l, r) * coef % MOD;
	};
    std::cout<<f(1, n) % MOD<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    calculateFactorial();
    int t;
    std::cin>>t;
    while(t--)
        solve();
}
