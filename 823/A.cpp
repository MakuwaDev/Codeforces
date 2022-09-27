#include <iostream>

constexpr int MAXORBIT = 110;

void solve()
{
    int n, c, x;
    int orbit[MAXORBIT];
    for(int i = 0; i < MAXORBIT; ++i)
        orbit[i] = 0;
    std::cin>>n>>c;
    for(int i = 0; i < n; ++i)
    {
        std::cin>>x;
        ++orbit[x];
    }
    x = 0;
    for(int i = 0; i < MAXORBIT; ++i)
        x += std::min(orbit[i], c);
    std::cout<<x<<"\n";
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
