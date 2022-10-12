#include <iostream>
#include <set>
#include <vector>

long long sum(std::multiset<long long, std::greater<long long>>& s)
{
    long long res = 0;
    for(auto x : s)
        res += x;
    return res;
}

void solve()
{
    int n, k;
    bool xd;
    long long res, bigsum, smallsum;
    std::cin>>n;
    std::multiset<long long, std::greater<long long>> fire;
    std::multiset<long long, std::greater<long long>> ice;
    std::vector<bool> type(n);
    for(int i = 0; i < n; ++i)
    {
        std::cin>>xd;
        type[i] = xd;
    }
    for(int i = 0; i < n; ++i)
    {
        std::cin>>res;
        if(type[i]) fire.insert(res);
        else ice.insert(res);
    }
    res = 0;
    if(ice.size() == fire.size())
    {
        res = 2 * (sum(ice) + sum(fire));
        smallsum = *fire.rbegin();
        bigsum = *ice.rbegin();
        res -= std::min(smallsum, bigsum);
        std::cout<<res<<"\n";
        return;
    }
    if(ice.size() < fire.size())
    {
        res = 2 * sum(ice) + sum(fire);
        auto it = fire.begin();
        for(int i = 0; i < ice.size(); ++i)
        {
            res += *it;
            ++it;
        }
        std::cout<<res<<"\n";
        return;
    }
    if(ice.size() > fire.size())
    {
        res = sum(ice) + 2 * sum(fire);
        auto it = ice.begin();
        for(int i = 0; i < fire.size(); ++i)
        {
            res += *it;
            ++it;
        }
        std::cout<<res<<"\n";
        return;
    }
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
