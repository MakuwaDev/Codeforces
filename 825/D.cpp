#include <iostream>
#include <vector>

void solve()
{
    int n;
    std::string s;
    std::vector<std::pair<int, int>> indices;
    std::cin>>n;
    std::cin>>s;
    for(int i = 0; i < 2 * n; i += 2)
    {
        if(s[i] != s[i + 1])
        {
            if(s[i] == '0') indices.push_back({i, i + 1});
            else indices.push_back({i + 1, i});
        }
    }
    if(indices.size() % 2 == 1)
    {
        std::cout<<"-1\n";
        return;
    }
    std::cout<<indices.size()<<" ";
    for(int i = 0; i < indices.size(); ++i)
    {
        if(i % 2 == 0) std::cout<<indices[i].first + 1<<" ";
        else std::cout<<indices[i].second + 1<<" ";
    }
    std::cout<<"\n";
    for(int i = 1; i <= 2 * n; i += 2)
        std::cout<<i<<" ";
    std::cout<<"\n";
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
