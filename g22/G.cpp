#include <iostream>
#include <vector>

int n, k;

std::pair<int, int> cell(int diag, int pos)
{
    int st_x = 0, st_y = 0;
    if(diag <= n - 1) st_y = (n - 1) - diag;
    if(diag >= n - 1) st_x = diag - (n - 1);
    return {st_x + pos, st_y + pos};
}

void solve()
{
    std::cin>>n>>k;
    std::vector<std::string> s(n);
    std::string full = "";
    for(int i = 0; i < n; ++i)
        std::cin>>s[i];
    for(int i = 0; i < n; i++)
        full.push_back('1');
    std::vector<std::string> t(n, full);
    std::vector<int> last_deleted(2 * n - 1, -1);
    int m = n - k + 1;
    for(int iter = 0; iter <= 2 * (m - 1); ++iter)
    {
        std::vector<std::pair<int, int>> updates;
        for(int diag = 0; diag <= 2 * (n - 1); diag++)
            if(std::abs(diag - (n - 1)) <= std::min(iter, 2 * (m - 1) - iter) && std::abs(diag - (n - 1)) % 2 == iter % 2)
            {
                int next = last_deleted[diag] + 1;
                if(diag - 1 < n - 1) next = std::max(next, last_deleted[diag - 1] + 1);
                else next = std::max(next, last_deleted[diag - 1]);
                if (diag + 1 > n - 1) next = std::max(next, last_deleted[diag + 1] + 1);
                else next = std::max(next, last_deleted[diag + 1]);
                while(true)
                {
                    auto cur = cell(diag, next);
                    if(cur.first >= n || cur.second >= n)
                    {
                        std::cout<<"NO\n";
                        return;
                    }
                    if(s[cur.first][cur.second] == '0') ++next;
                    else
                    {
                        t[cur.first][cur.second] = '0';
                        break;
                    }
                }
                updates.push_back({diag, next});
            }
        for (auto x : updates)
            last_deleted[x.first] = x.second;
    }
    std::cout<<"YES\n";
    for(auto x : t)
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
