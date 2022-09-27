#include <iostream>

void solve()
{
    int n;
    std::cin>>n;
    if(n == 1) std::cout<<"1\n";
    else if(n == 2) std::cout<<"1\n1 1\n";
    else
    {
        std::cout<<"1\n1 1\n";
        for(int i = 3; i <= n; ++i)
        {
            std::cout<<"1 ";
            for(int j = 0; j < i - 2; ++j)
                std::cout<<"0 ";
            std::cout<<"1\n";
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
