#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

constexpr int MAXN = 10005;
constexpr int K = 12;
constexpr int INF = 1e9;

int tsz = 0;
int trie[MAXN][K];
int aut[MAXN][K];
int link[MAXN];
int p[MAXN];
int pchar[MAXN];
int cost[MAXN];
int ncost[MAXN];

int newNode()
{
    link[tsz] = -1;
    ncost[tsz] = -1;
    cost[tsz] = 0;
    for(int i = 0; i < K; ++i)
        trie[tsz][i] = aut[tsz][i] = -1;
    return tsz++;
}

int next(int x, int y)
{
    if(trie[x][y] == -1)
    {
        trie[x][y] = newNode();
        pchar[trie[x][y]] = y;
        p[trie[x][y]] = x;
    }
    return trie[x][y];
}

int go(int x, int y);

int get_link(int x)
{
    if(link[x] != -1) return link[x];
    int &d = link[x];
    if(x == 0 || p[x] == 0) return d = 0;
    return d = go(get_link(p[x]), pchar[x]);
}

int go(int x, int y)
{
    if(aut[x][y] != -1) return aut[x][y];
    int& d = aut[x][y];
    if(trie[x][y] != -1) return d = trie[x][y];
    if(x == 0) return d = 0;
    return d = go(get_link(x), y);
}

void add(std::string s, int c)
{
    int cur = 0;
    for(auto x : s) cur = next(cur, x - 'a');
    cost[cur] += c;
}

int calc(int x)
{
    if(ncost[x] != -1) return ncost[x];
    ncost[x] = cost[x];
    int y = get_link(x);
    if(y != x) ncost[x] += calc(y);
    return ncost[x];
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int root = newNode();
    int n, nmask, curmask = (1 << K) - 1, curstate, cc, ns, nstate, added;
    std::string ans;
    std::cin>>n;
    for(int i = 0; i < n; ++i)
    {
        std::string s, res = "";
        int x;
        char c;
        bool bad = false;
        std::map<char, std::set<char>> adjacent;
        std::map<char, int> pos;
        std::cin>>x>>s;
        for(int j = 0; j + 1 < s.size(); ++j)
        {
            adjacent[s[j]].insert(s[j + 1]);
            adjacent[s[j + 1]].insert(s[j]);
        }
        for(c = 'a'; c <= 'l'; ++c)
        {
            if(!adjacent.count(c)) continue;
            if(adjacent[c].size() >= 3) bad = true;
            if(adjacent[c].size() == 1) break;
        }
        if(c == 'm' || bad) continue;
        res.push_back(c);
        while(adjacent[c].size() > 0)
        {
            char d = *adjacent[c].begin();
            adjacent[c].erase(d);
            adjacent[d].erase(c);
            c = d;
            res.push_back(c);
        }
        if(adjacent.size() != res.size()) bad = true;
        for(int i = 0; i < res.size(); ++i)
            pos[res[i]] = i;
        for(int i = 0; i + 1 < s.size(); i++)
            if(std::abs(pos[s[i]] - pos[s[i + 1]]) > 1) bad = true;
        if(bad) continue;
        add(res, x);
        std::reverse(res.begin(), res.end());
        add(res, x);
    }
    std::vector<std::vector<int>> dp(1 << K, std::vector<int>(tsz + 1, -INF));
    std::vector<std::vector<std::pair<int, int>>> pdp(1 << K, std::vector<std::pair<int, int>>(tsz + 1));
    dp[0][0] = 0;
    for(int i = 0; i < (1 << K); ++i)
        for(int j = 0; j < tsz; ++j)
            for(int z = 0; z < K; ++z)
            {
                if(i & (1 << z)) continue;
                nstate = go(j, z);
                added = calc(nstate);
                nmask = i | (1 << z);
                if(dp[nmask][nstate] < dp[i][j] + added)
                {
                    dp[nmask][nstate] = dp[i][j] + added;
                    pdp[nmask][nstate] = {z, j};
                }
            }
    curstate = std::max_element(dp[curmask].begin(), dp[curmask].end()) - dp[curmask].begin();
    while(curmask != 0)
    {
        cc = pdp[curmask][curstate].first;
        ns = pdp[curmask][curstate].second;
        ans.push_back(char('a' + cc));
        curmask ^= (1 << cc);
        curstate = ns;
    }
    std::cout<<ans;
}
