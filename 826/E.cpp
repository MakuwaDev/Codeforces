#include <iostream>
#include <vector>

void solve()
{
    int n;
    std::cin>>n;
    std::vector<int> b(n + 1);
    std::vector<bool> dp(n + 1, false);
    for(int i = 1; i <= n; ++i)
        std::cin>>b[i];
    dp[0] = true;
    for(int i = 1; i<= n; ++i)
    {
        if(i + b[i] <= n && dp[i - 1]) dp[i + b[i]] = true;
        if(i - b[i] - 1 >= 0 && dp[i - b[i] - 1]) dp[i] = true;
    }
    if(dp[n]) std::cout<<"YES\n";
    else std::cout<<"NO\n";
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
