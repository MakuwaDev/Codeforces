#include <iostream>
#include <vector>
#include <cmath>

void solve()
{
    int n, delta = 0, diff = 0, ax = 0, bx = 0;
    std::cin>>n;
    std::vector<int> a(n);
    std::vector<int> b(n);
    for(int i = 0; i < n; ++i)
        std::cin>>a[i];
    for(int i = 0; i < n; ++i)
        std::cin>>b[i];
    for(int i = 0; i < n; ++i)
    {
        ax += a[i];
        bx += b[i];
        if(a[i] != b[i]) ++diff;
    }
    delta = std::abs(ax - bx);
    std::cout<<std::min(diff, delta + 1)<<"\n";
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
