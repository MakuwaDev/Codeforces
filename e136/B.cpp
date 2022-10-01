#include <iostream>
#include <vector>

void solve()
{
    int n, a, b;
    std::vector<int> recovered,transformed;
    std::cin>>n;
    for(int i = 0; i < n; ++i)
    {
        std::cin>>a;
        transformed.push_back(a);
    }
    recovered.push_back(transformed[0]);
    for(int i = 1; i < n; ++i)
    {
        a = recovered[i - 1] - transformed[i];
        b = recovered[i - 1] + transformed[i];
        if(a >= 0 && b >= 0 && a != b)
        {
            std::cout<<"-1\n";
            return;
        }
        if(a < b) std::swap(a, b);
        recovered.push_back(a);
    }
    for(auto x: recovered)
        std::cout<<x<<" ";
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
