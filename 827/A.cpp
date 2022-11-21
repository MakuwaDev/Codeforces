#include <iostream>

void solve()
{
    int a, b, c;
    std::cin>>a>>b>>c;
    if(a == b + c || b == a + c || c == a + b) std::cout<<"YES\n";
    else std::cout<<"NO\n";
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
