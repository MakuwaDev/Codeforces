#include <iostream>
#include <vector>
#include <limits>

constexpr int MAXN = (int)2e5+5;
constexpr int INF = std::numeric_limits<int>::max();

int w, m, n;
std::string s;

std::vector<int> D[9];
int ps[MAXN];

void build()
{
    for(int i = 0; i < 9; ++i)
        D[i].clear();
    ps[0] = 0;
    for(int i = 1; i <= n; ++i)
        ps[i] = ps[i - 1] + s[i - 1] - '0';
    for(int i = 1; i + w - 1 <= n; ++i)
        D[(ps[i + w - 1] - ps[i - 1]) % 9].push_back(i);
}

std::pair<int, int> solve(int l, int r, int k)
{
    int x = (ps[r] - ps[l - 1]) % 9;
    std::pair<int, int> res = {INF, INF};
    for(int a = 0; a < 9; ++a)
    {
        int b = (k - ((a * x) % 9))% 9;
        if(b < 0) b+= 9;
        if(D[a].empty() || D[b].empty()) continue;
        if(a != b) res = std::min(res, {D[a][0], D[b][0]});
        else if(D[a].size() >= 2) res = std::min(res, {D[a][0], D[a][1]});
    }
    if(res == std::make_pair(INF, INF)) return {-1, -1};
    else return res;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin>>t;
    while(t--)
    {
        std::cin>>s>>w>>m;
        n = s.size();
        build();
        for(int i = 0; i < m; ++i)
        {
            int l, r, k;
            std::pair<int, int> res;
            std::cin>>l>>r>>k;
            res = solve(l, r, k);
            std::cout<<res.first<<" "<<res.second<<"\n";
        }
    }
}
