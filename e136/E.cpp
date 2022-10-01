#include <iostream>
#include <limits>
#include <vector>

constexpr int INF = std::numeric_limits<int>::min();
constexpr int MAXN = 2e5+5;

int dp[MAXN][2][2];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::vector<std::string> s(2);
    std::cin>>n;
    for(int i = 0; i < 2; ++ i)
        std::cin>>s[i];
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j < 2; ++ j)
            for(int k = 0; k < 2; ++k)
                dp[i][j][k] = INF;
    dp[0][0][s[1][0] == '1'] = s[1][0] == '1';
    dp[0][0][0] = 0;
   	for(int i = 0; i < n - 1; ++i)
        for(int j = 0; j < 2; ++j)
        {
            int nxtj = s[j][i + 1] == '1';
            int nxtj1 = s[j ^ 1][i + 1] == '1';
            dp[i + 1][j ^ 1][0] = std::max(dp[i + 1][j ^ 1][0], dp[i][j][1] + nxtj1);
            dp[i + 1][j][nxtj1] = std::max(dp[i + 1][j][nxtj1], dp[i][j][0] + nxtj1 + nxtj);
            dp[i + 1][j][0] = std::max(dp[i + 1][j][0], dp[i][j][0] + nxtj);
        }
    std::cout<<std::max(std::max(dp[n - 1][0][0], dp[n - 1][0][1]), std::max(dp[n - 1][1][0], dp[n - 1][1][1])) << '\n';
}
