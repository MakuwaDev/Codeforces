#include <iostream>
#include <algorithm>
#include <limits>

constexpr int MAXN = 310;
constexpr int INF = std::numeric_limits<int>::max();

int tab[MAXN];

void solve()
{
    int n, res = INF;
    std::cin>>n;
    for(int i = 0; i < n; ++i)
        std::cin>>tab[i];
    std::sort(tab, tab + n);
    for(int i = 2; i < n; ++i)
        res = std::min((tab[i] - tab[i - 1]) + (tab[i - 1] - tab[i - 2]), res);
    std::cout<<res<<"\n";
    for(int i = 0; i < n; ++i)
        tab[i] = 0;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin>>t;
    while(t--)
        solve();
}
