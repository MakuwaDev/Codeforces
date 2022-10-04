#include <iostream>
#include <vector>
#include <algorithm>

void solve()
{
    int n;
    long long res = 0, cut;
    std::vector<long long> tangrines;
    std::cin>>n;
    for(int i = 0; i < n; ++i)
    {
        std::cin>>cut;
        tangrines.push_back(cut);
    }
    std::sort(tangrines.begin(), tangrines.end());
    cut = tangrines[0];
    for(int i = 1; i < n; ++i)
    {
        res += tangrines[i] / (2 * cut - 1);
        if(tangrines[i] % (2 * cut - 1) == 0) --res;
    }
    std::cout<<res<<"\n";
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
