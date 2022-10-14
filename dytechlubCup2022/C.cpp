#include <iostream>
#include <vector>

void solve()
{
    int n, x, y;
    std::pair<int, int> first, mid, second;
    std::cin>>n;
    std::cin>>first.first>>first.second>>mid.first>>mid.second>>second.first>>second.second;
    std::cin>>x>>y;
    std::vector<int> checkr(n + 1), checkc(n + 1);
    ++checkr[first.first];
    ++checkr[mid.first];
    ++checkr[second.first];
    ++checkc[first.second];
    ++checkc[mid.second];
    ++checkc[second.second];
    if(checkr[first.first] == 2 && checkc[first.second] == 2) std::swap(first, mid);
    if(checkr[second.first] == 2 && checkc[second.second] == 2) std::swap(second, mid);
    if(mid.first == n && mid.second == n)
    {
        if(y == n || x == n) std::cout<<"YES\n";
        else std::cout<<"NO\n";
        return;
    }
    if(mid.first == n && mid.second == 1)
    {
        if(y == 1 || x == n) std::cout<<"YES\n";
        else std::cout<<"NO\n";
        return;
    }
    if(mid.first == 1 && mid.second == n)
    {
        if(x == 1 || y == n) std::cout<<"YES\n";
        else std::cout<<"NO\n";
        return;
    }
    if(mid.first == 1 && mid.second == 1)
    {
        if(x == 1 || y == 1) std::cout<<"YES\n";
        else std::cout<<"NO\n";
        return;
    }
    if(((x + mid.first) % 2 == 0) || ((y + mid.second) % 2 == 0)) std::cout<<"YES\n";
    else std::cout<<"NO\n";
    return;
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
