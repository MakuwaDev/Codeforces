#include <iostream>

void solve()
{
    long long n, x, y, d = 0;
    std::cin>>n>>x>>y;
    std::string a, b;
    std::cin>>a>>b;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == b[i]) a[i] = '0';
        else a[i] = '1';
    }
    for(int i = 0; i < n; ++i)
        if(a[i] == '1') ++d;
    if(d % 2 == 1) std::cout<<"-1\n";
    else if(d == 2)
    {
        int l, r;
        for(l = 0; l < n; ++l)
            if(a[l] == '1') break;
        for(r = n - 1; r >= 0; --r)
            if(a[r] == '1') break;
        if(r == l + 1) std::cout<<std::min(x, 2 * y)<<"\n";
        else std::cout<<std::min((r - l) * x, y)<<"\n";
    }
    else std::cout<<(d / 2) * y<<"\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin>>t;
    while(t--) solve();
}
