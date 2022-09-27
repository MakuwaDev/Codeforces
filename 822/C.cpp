#include <iostream>
#include <vector>

constexpr int MAXN = 1e6+6;

bool s[MAXN];

void solve()
{
    int n;
    long long res = 0;
    std::string t;
    std::cin>>n;
    std::cin>>t;
    for(int i = 0; i <= n; ++i)
        s[i] = true;
    for(int k = 1; k <= n; ++k)
    {
        bool czy = false;
        int curr = 0;
        for(int i = k; i <= n; i += k)
        {
            if(s[i] && t[i - 1] == '1') break;
            if(s[i] && t[i - 1] == '0')
            {
                s[i] = false;
                czy = true;
                curr += k;
            }
        }
        if(czy) res += curr;
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

