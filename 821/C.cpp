#include <iostream>

constexpr int MAXN = 1e5+5;

int a[MAXN];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t, n;
    std::cin>>t;
    for(int l = 0; l < t; ++l)
    {
        std::cin>>n;
        for(int i = 1; i <= n; ++i)
            std::cin>>a[i];
        std::cout<<n - 1<<"\n";
        if(n == 1) continue;
        std::cout<<"1 "<<n<<"\n";
        for(int i = 2; i <= n - 1; ++i)
        {
            if(((a[i] + a[1]) & 1) == 0) std::cout<<i<<" "<<n<<"\n";
            else std::cout<<"1 "<<i<<"\n";
        }
    }
}
