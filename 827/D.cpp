#include <iostream>
#include <vector>
#include <numeric>

std::vector<int> pairs[1001];

void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> id[1001];
    for(int i = 1; i <= n; ++i)
    {
        int x;
        std::cin >> x;
        id[x].push_back(i);
    }
    int ans = -1;
    for(int i = 1; i <= 1000; ++i)
        for(int j : pairs[i])
            if(!id[i].empty() && !id[j].empty()) ans = std::max(ans, id[i].back() + id[j].back());
    std::cout << ans << "\n";
}

int main()
{
    for(int i = 1; i <= 1000; ++i)
        for(int j = 1; j <= 1000; ++j)
            if(std::gcd(i, j) == 1)
                pairs[i].push_back(j);
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while(t--)
        solve();
}
