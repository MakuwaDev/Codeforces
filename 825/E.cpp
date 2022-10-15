#include <iostream>
#include <vector>

constexpr int MAXN = 505;

std::vector<std::vector<std::vector<int>>> dp(MAXN, std::vector<std::vector<int>>(MAXN, std::vector<int>(MAXN, -(int)1e9)));

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, res = 0;
    std::cin>>n;
    std::vector<int> a(n + 5);
    std::vector<std::vector<int>> pref(n + 5, std::vector<int>(n + 5, 0));
    for(int i = 1; i <= n; ++i)
        std::cin>>a[i];
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
            for(int k = 0; k <= i; ++k)
            {
                if(k) dp[i][j][k] = dp[i - 1][j][k - 1] + a[j];
                if(j >= i)
                {
                    int need = j - i;
                    if(need > k) continue;
                    dp[i][j][k] = std::max(dp[i][j][k], pref[k - need][j - 1] + a[j]);
                }
            }
        for(int j = 1; j <= n; ++j)
            for(int k = 0; k <= i; ++k)
                pref[k][j] = std::max(pref[k][j], dp[i][j][k]);
        for(int j = 0; j <= i; ++j)
            for(int k = 1; k <= n; ++k)
            {
                pref[j][k] = std::max(pref[j][k], pref[j][k - 1]);
                res = std::max(res, pref[j][k]);
            }
    }
    std::cout<<res;
}
