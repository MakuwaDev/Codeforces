#include <iostream>
#include <map>

bool oddCharacters(std::string& s, std::string& t)
{
    std::map<char, int> mp;
    for(auto x : s)
        ++mp[x];
    for(auto x : t)
        ++mp[x];
    for(auto x : mp)
        if(x.second % 2 == 1) return true;
    return false;
}

std::pair<char, char> formPair(char a, char b)
{
    if(a > b) std::swap(a, b);
    return {a, b};
}

void solve()
{
    int n, odd = 0;
    std::string s1, s2;
    std::map<std::pair<char, char>, int> mp;
    std::cin>>n;
    std::cin>>s1;
    std::cin>>s2;
    if(oddCharacters(s1, s2))
    {
        std::cout<<"NO\n";
        return;
    }
    for(int i = 0; i < n; ++i)
        ++mp[formPair(s1[i], s2[n - i - 1])];
    for(auto x: mp)
    {
        if(x.second % 2 == 1)
        {
            if(x.first.first != x.first.second)
            {
                std::cout<<"NO\n";
                return;
            }
            ++odd;
        }
    }
    if(odd > 1) std::cout<<"NO\n";
    else if(odd == 1 && n % 2 == 1) std::cout<<"YES\n";
    else if(n % 2 == 1) std::cout<<"NO\n";
    else std::cout<<"YES\n";
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
