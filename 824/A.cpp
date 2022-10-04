#include <iostream>

void solve()
{
    int x;
    std::cin>>x;
    x -= 4;
    if(x % 3 == 0) std::cout<<x / 3 - 1;
    else if(x % 3 == 1) std::cout<< x / 3 - 1;
    else if(x % 3 == 2) std::cout<<x / 3;
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
