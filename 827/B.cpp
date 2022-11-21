#include <iostream>
#include <vector>
#include <algorithm>

void solve()
{
    int n;
    std::vector<int> t;
    std::cin>>n;
    t.resize(n);
    for(int i = 0; i < n; ++i)
        std::cin>>t[i];
    std::sort(t.begin(), t.end());
    for(int i = 1; i < n; ++i)
        if(t[i] == t[i - 1])
        {
            std::cout<<"NO\n";
            return;
        }
    std::cout<<"YES\n";
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
