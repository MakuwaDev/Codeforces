#include <iostream>
#include <queue>
#include <vector>

int query(int x)
{
    int y;
    std::cout<<"? "<<x<<"\n";
    std::cout.flush();
    std::cin>>y;
    return y;
}

void solve()
{
    int n, k;
    std::cin >> n;
    std::vector<int> d(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> d[i];
    auto query = [&](int x)
    {
        std::cout << "? " << x << "\n";
        std::cout.flush();
        int y;
        std::cin >> y;
        return y;
    };
    std::vector<int> visited(n + 1);
    std::vector<int> res(n + 1);
    int color_cnt = 0;
    while (true)
    {
        int x = 0;
        for (int i = 1; i <= n; ++i)
            if (!visited[i] && d[i] >= d[x]) x = i;
        if (x == 0) break;
        std::vector<int> q = { x };
        int colored_vertex = 0;
        for (int i = 1; i <= d[x]; ++i)
        {
            int y = query(x);
            if (visited[y])
            {
                colored_vertex = y;
                break;
            }
            q.push_back(y);
        }
        int color = colored_vertex == 0 ? ++color_cnt : res[colored_vertex];
        for (auto z : q)
        {
            visited[z] = 1;
            res[z] = color;
        }
    }
    std::cout << "!";
    for (int i = 1; i <= n; ++i)
        std::cout << " " << res[i];
    std::cout << "\n";
    std::cout.flush();
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
