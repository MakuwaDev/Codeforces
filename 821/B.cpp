#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t, n, x, y;
    std::cin>>t;
    for(int l = 0; l < t; ++l)
    {
        std::cin>>n>>x>>y;
        if(x != 0 && y != 0)
        {
            std::cout<<"-1\n";
            continue;
        }
        if(x == 0 && y == 0)
        {
            std::cout<<"-1\n";
            continue;
        }
        if(x == 0) std::swap(x, y);
        if((n - 1) % x != 0)
        {
            std::cout<<"-1\n";
            continue;
        }
        int i = 2;
        if(n == 2)
        {
            std::cout<<"1\n";
            continue;
        }
        while(i <= n)
        {
            for(int j = 0; j < x; ++j)
            {
                std::cout<<i<<" ";
            }
            i += x;
        }
        std::cout<<"\n";
    }
}
