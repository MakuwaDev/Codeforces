#include <iostream>

constexpr int MAXN = 110;

long long tab[MAXN];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t, n, k;
    long long res, maks;
    std::cin>>t;
    for(int l = 0; l < t; ++l)
    {
        std::cin>>n>>k;
        res = 0;
        for(int i = 1; i <= n; ++i)
            std::cin>>tab[i];
        for(int start = 1; start <= k; ++start)
        {
            maks = 0;
            for(int i = start; i <= n; i += k)
                maks = std::max(maks, tab[i]);
            res += maks;
        }
        std::cout<<res<<"\n";
    }
}
