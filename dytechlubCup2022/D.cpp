#include <iostream>
#include <vector>

constexpr int MAXN = 505;

long long dist[MAXN][MAXN];

void solve()
{
    int n, m, u, v, w;
    long long res = 1e18;
    std::vector<std::pair<std::pair<int, int>, int>> edges;
    std::cin>>n>>m;
    for(int i = 0; i <= n; ++i)
    {
        for(int j = 0; j <= n; ++j)
            dist[i][j] = 1e18;
        dist[i][i] = 0;
    }
    for(int i = 0; i < m; ++i)
    {
        std::cin>>u>>v>>w;
        dist[u - 1][v - 1] = 1;
        dist[v - 1][u - 1] = 1;
        edges.push_back({{u - 1, v - 1}, w});
    }
    for(int x = 0; x < n; ++x)
        for(int a = 0; a < n; ++a)
            for(int b = 0; b < n; ++b)
                dist[a][b] = std::min(dist[a][b], dist[a][x] + dist[x][b]);
    for(auto x : edges)
    {
        u = x.first.first;
        v = x.first.second;
        w = x.second;
        res = std::min(res, (long long) w * (dist[0][u] + dist[n - 1][v] + 1));
        res = std::min(res, (long long) w * (dist[0][v] + dist[n - 1][u] + 1));
        for(int i = 0; i < n; ++i)
        {
            res = std::min(res, (long long) w * (dist[v][i] + 1 + dist[i][0] + dist[i][n - 1] + 1));
            res = std::min(res, (long long) w * (dist[u][i] + 1 + dist[i][0] + dist[i][n - 1] + 1));
        }
    }
    std::cout<<res<<"\n";
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
