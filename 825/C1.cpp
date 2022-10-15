#include <iostream>
#include <vector>

void solve()
{
    int n;
    long long res = 0;
    std::cin>>n;
    std::vector<long long> a(n + 1);
    std::vector<long long> dp(n + 1);
    for(int i = 1; i <= n; ++i)
        std::cin>>a[i];
    dp[0] = 1;
    for(int i = 2; i <= n; ++i)
        dp[i] = std::min(dp[i - 1] + 1, a[i]);
    for(auto x : dp)
        res = res + x;
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
