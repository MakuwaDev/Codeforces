#include <iostream>
#include <vector>
#include <algorithm>

void solve()
{
    long long n, a, poor, rich, res = 0;
    std::vector<long long> friends;
    std::cin>>n;
    for(int i = 0; i < n; ++i)
    {
        std::cin>>a;
        friends.push_back(-a);
    }
    for(int i = 0; i < n; ++i)
    {
        std::cin>>a;
        friends[i] += a;
    }
    std::sort(friends.begin(), friends.end());
    std::reverse(friends.begin(), friends.end());
    poor = n - 1;
    rich = 0;
    for(rich = 0; rich < n; ++rich)
    {
        while(poor > rich && friends[poor] + friends[rich] < 0)
            --poor;
        if(poor <= rich) break;
        ++res;
        --poor;
    }
    std::cout<<res<<"\n";
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
