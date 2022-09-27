#include <iostream>
#include <vector>

void solve()
{
    int n, a, mx, mn;
    std::vector<int> x;
    std::vector<int> t;
    std::cin>>n;
    for(int i = 0; i < n; ++i)
    {
        std::cin>>a;
        x.push_back(a);
    }
    for(int i = 0; i < n; ++i)
    {
        std::cin>>a;
        t.push_back(a);
    }
    for(int i = 0; i < n; ++i)
    {
        a = x[i];
        x[i] = a - t[i];
        x.push_back(a + t[i]);
    }
    mx = mn = x[0];
    for(int i = 1; i < x.size(); ++i)
    {
        mx = std::max(mx, x[i]);
        mn = std::min(mn, x[i]);
    }
    std::cout<<(mn + mx) / 2;
    if((mn + mx) % 2 == 1) std::cout<<".5";
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
