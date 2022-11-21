#include <iostream>
#include <vector>

void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; ++i)
        std::cin >> a[i];
    int cur_or = 0;
    std::vector<bool> vis(n, false);
    for(int i = 0; i < std::min(31, n); ++i)
    {
        int mx = 0, idx = -1;
        for(int j = 0; j < n; ++j)
        {
            if(vis[j]) continue;
            if((cur_or | a[j]) > mx)
            {
                mx = (cur_or | a[j]);
                idx = j;
            }
        }
        vis[idx] = true;
        std::cout << a[idx] << " ";
        cur_or |= a[idx];
    }
    for(int i = 0; i < n; ++i)
        if(!vis[i]) std::cout << a[i] << " ";
    std::cout << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while(t--)
        solve();
}
