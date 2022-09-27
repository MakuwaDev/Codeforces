#include <iostream>

constexpr int MAXN = 125;

long long conveyor[MAXN][MAXN];

void solve()
{
    int x, y, u, v;
    long long t;
    std::cin>>t>>x>>y;
    t -= x + y;
    if(t < 0)
    {
        std::cout<<"NO\n";
        return;
    }
    conveyor[0][0] = t;
    for(int i = 0; i < MAXN - 1; ++i)
        for(int j = 0; j < MAXN - 1; ++j)
        {
            conveyor[i][j + 1] += (conveyor[i][j] + 1) / 2;
            conveyor[i + 1][j] += conveyor[i][j] / 2;
        }
    u = v = 0;
    while(u < 120 && v < MAXN)
    {
        if(u == x && v == y) break;
        if(conveyor[u][v] & 1) ++u;
        else ++v;
    }
    if(u == x && v == y) std::cout<<"YES\n";
    else std::cout<<"NO\n";
    for(int i = 0; i < MAXN; ++i)
        for(int j = 0; j < MAXN; ++j)
            conveyor[i][j] = 0;
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
