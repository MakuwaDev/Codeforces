#include <iostream>
#include <vector>

void solve()
{
    long long n, k, last;
    std::vector<long long> s;
    std::cin>>n>>k;
    s.resize(k);
    for(long long i = 0; i < k; ++i)
        std::cin>>s[i];
    last = s[0] / (n - k + 1);
    if(s[0] % (n - k + 1) != 0 && s[0] >= 0) ++last;
    for(long long i = 1; i < k; ++i)
    {
        if(s[i] - s[i - 1] < last)
        {
            std::cout<<"No\n";
            return;
        }
        last = s[i] - s[i - 1];
    }
    std::cout<<"Yes\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long t;
    std::cin>>t;
    while(t--)
        solve();
}
