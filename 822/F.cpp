#include <iostream>
#include <map>


std::map<std::pair<long long, long long>, long long> cache;

long long solve(long long n, long long k)
{
    if(k == 0) return 0;
    if(k == 1) return __builtin_popcountll(n) & 1;
    long long t, x, one_cell, zero_cell, cnt1, cnt0, res;
    if(k % 2 == 1)
    {
        t = solve(n, k - 1);
        x = __builtin_popcountll((k - 1) ^ (n + k - 1)) & 1;
        return t + x;
    }
    if(cache.find({n, k}) != cache.end()) return cache[{n, k}];
    if(n % 2 == 0)
    {
        one_cell = 2;
        zero_cell = 0;
        cnt1 = solve(n / 2, k / 2);
        cnt0 = k / 2 - cnt1;
    }
    else
    {
        one_cell = 0;
        zero_cell = 1;
        cnt1 = solve(n / 2, k / 2) + solve(n / 2 + 1, k / 2);
        cnt0 = k - cnt1;
    }
    res = one_cell * cnt1 + zero_cell * cnt0;
    cache[{n, k}] = res;
    return res;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin>>t;
    while(t--)
    {
        long long n, k;
        std::cin>>n>>k;
        std::cout<<solve(n, k)<<"\n";
    }
}
