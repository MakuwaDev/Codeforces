#include <iostream>

void solve()
{
    int n, m;
    std::cin>>n>>m;
    std::cout<< n / 2 + 1<<" "<<m / 2 + 1<<"\n";
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
