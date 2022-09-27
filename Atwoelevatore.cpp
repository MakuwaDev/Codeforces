#include <iostream>
#include <cmath>

void solve()
{
    int a, b, c, first, second;
    std::cin>>a>>b>>c;
    first = std::abs(a - 1);
    second = std::abs(c - b) + std::abs(c - 1);
    if(first < second) std::cout<<"1\n";
    else if(first > second) std::cout<<"2\n";
    else std::cout<<"3\n";
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
