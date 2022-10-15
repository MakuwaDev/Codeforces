#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    long long x, p;
    std::cin>>n;
    std::vector<long long> track(n + 5,0);
    std::vector<long long> sum(n + 5,0);
    std::vector<std::pair<long long, std::pair<long long, long long>>> trav;
    std::vector<long long> pref(n + 5,0);
    std::vector<long long> dp(n + 5,0);
    std::set<long long> found;
    for(int i = 1;i <= n; ++i)
    {
        std::cin>>x;
        sum[i] = sum[i - 1] + i;
        trav.push_back({x - i, {i, 0}});
        dp[i] = std::min(dp[i - 1] + 1, x);
        pref[i] = pref[i - 1] + dp[i];
    }
    std::cin>>q;
    std::vector<long long> res(q + 1,0);
    for(int i = 1;i <= q; ++i)
    {
        std::cin>>p>>x;
        x = std::min(dp[p - 1] + 1, x);
        trav.push_back({x - p, {p, i}});
    }
    found.insert(n + 1);
    std::sort(trav.begin(), trav.end());
    for(auto it:trav)
    {
        if(it.second.second)
        {
            long long r = *found.upper_bound(it.second.first);
            res[it.second.second] = pref[it.second.first - 1] + track[r] + sum[r - it.second.first] + (it.first + it.second.first - 1) * (r - it.second.first);
        }
        else
        {
            long long r = *found.lower_bound(it.second.first);
            found.insert(it.second.first);
            track[it.second.first] = track[r] + sum[r - it.second.first] + (it.first + it.second.first - 1) * (r - it.second.first);
        }
    }
    for(int i = 1; i <= q; ++i)
        std::cout<<res[i]<<"\n";
}
