#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

constexpr int MAXN = 10005;
constexpr int MAXF = 9;

std::vector<int> graph[MAXN];
int dist[MAXF][MAXN];
bool car[MAXN];

void bfs(int start, int id)
{
    std::queue<int> q;
    q.push(start);
    dist[id][start] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto x : graph[v])
        {
            if (dist[id][x] > dist[id][v] + 1)
            {
                q.push(x);
                dist[id][x] = dist[id][v] + 1;
            }
        }
    }
}

void solve()
{
    int n, m, f, k;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        graph[i].clear();
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < MAXF; j++)
            dist[j][i] = 2e9;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    std::cin >> f;
    std::vector<int> h(f + 1);
    for (int i = 1; i <= f; i++)
    {
        std::cin >> h[i];
        car[i] = true;
    }
    std::cin >> k;
    std::vector<int> p(k + 1);
    std::vector<int> pp;
    for (int i = 1; i <= k; i++)
    {
        std::cin >> p[i];
        pp.push_back(i);
        car[p[i]] = false;
    }
    bfs(1, 0);
    for (int i = 1; i <= k; i++)
        bfs(h[p[i]], i);
    int res = k;
    do
    {
        int lst = 0;
        for (int i = 1; i <= f; i++)
        {
            if (!car[i]) continue;
            int d = dist[0][h[i]], tmp = 1;
            while (lst < k && dist[pp[lst]][tmp] + dist[pp[lst]][h[i]] == d)
            {
                d -= dist[pp[lst]][tmp];
                tmp = h[p[pp[lst]]];
                lst++;
            }
        }
        res = std::min(res, k - lst);
    } while (std::next_permutation(pp.begin(), pp.end()));
    std::cout << res << '\n';
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
