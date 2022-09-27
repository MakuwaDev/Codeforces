#include <iostream>
#include <vector>

constexpr int MAXN = 5005;

std::vector<int> mis;
long long dp[MAXN];

void solve()
{
    mis.clear();
    int n;
    long long x, y, d = 0;
    std::string a, b;
    std::cin>>n>>x>>y;
    std::cin>>a;
    std::cin>>b;
    if(x >= y)
    {
        for(int i = 0; i < n; i++)
        {
            if(a[i] == b[i]) a[i] = '0';
            else a[i] = '1';
        }
        for(int i = 0; i < n; ++i)
            if(a[i] == '1') ++d;
        if(d % 2 == 1) std::cout<<"-1\n";
        else if(d == 2)
        {
            int l, r;
            for(l = 0; l < n; ++l)
                if(a[l] == '1') break;
            for(r = n - 1; r >= 0; --r)
                if(a[r] == '1') break;
            if(r == l + 1) std::cout<<std::min(x, 2 * y)<<"\n";
            else std::cout<<std::min((r - l) * x, y)<<"\n";
        }
        else std::cout<<(d / 2) * y<<"\n";
    }
    else
    {
        for(int i = 0; i < n;i++)
            if(a[i] != b[i]) mis.push_back(i);
        if(mis.size() % 2 !=0)
        {
            std::cout<<"-1\n";
            return;
        }
        else
        {
            if(mis.size() == 0)
            {
                std::cout<<"0\n";
                return;
            }
            dp[0] = dp[1] = 0;
            for(int i = 2;i <= mis.size(); i++)
            {
                dp[i] = dp[i - 2] + std::min(x * (mis[i - 1] - mis[i - 2]), y);
                if(i % 2 == 0) dp[i] = std::min(dp[i], dp[i - 1] + y);
                else dp[i] = std::min(dp[i], dp[i - 1]);
            }
            std::cout<<dp[mis.size()]<<"\n";
        }
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
