#include <iostream>

void solve()
{
    int n;
    std::cin>>n;
    if(n == 1 || n == 3)
    {
        std::cout<<"-1\n";
        return;
    }
    int i = 1;
    int j = n;
    while(i < j)
    {
        std::cout<<j<<" ";
        ++i;
        --j;
    }
    j = 1;
    while(i <= n)
    {
        std::cout<<j<<" ";
        ++j;
        ++i;
    }
    std::cout<<"\n";
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
