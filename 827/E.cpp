#include <iostream>
#include <vector>
#include <algorithm>

void solve()
{
    int n, q;
    long long leg;
    std::cin>>n>>q;
    std::vector<long long> step(n);
    std::vector<long long> height(n);
    std::vector<long long> maxstep(n);
    std::cin>>step[0];
    maxstep[0] = height[0] = step[0];
    for(int i = 1; i < n; ++i)
    {
        std::cin>>step[i];
        height[i] = height[i - 1] + step[i];
        maxstep[i] = std::max(maxstep[i - 1], step[i]);
    }
    for(int i = 0; i < q; ++i)
    {
        std::cin>>leg;
        auto it = std::upper_bound(maxstep.begin(), maxstep.end(), leg);
        if(it == maxstep.end())
        {
            std::cout<<height[n - 1]<<" ";
            continue;
        }
        if(it == maxstep.begin())
        {
            std::cout<<"0 ";
            continue;
        }
        std::cout<<height[it - maxstep.begin() - 1]<<" ";
    }
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
