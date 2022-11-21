#include <iostream>
#include <vector>

void solve()
{
    int q, k, d, lasts, lastt;
    std::string x;
    std::vector<int> s(26);
    std::vector<int> t(26);
    std::cin>>q;
    t[0] = s[0] = lasts = lastt = 1;
    for(int i = 0; i < q; ++i)
    {
        std::cin>>d>>k>>x;
        if(d == 1)
        {
            for(auto c : x)
            {
                s[c - 'a'] += k;
                lasts = std::max(lasts, c - 'a');
            }
        }
        else
        {
            for(auto c : x)
            {
                t[c - 'a'] += k;
                lastt = std::max(lastt, c - 'a');
            }
        }
        for(int j = 0; j < 26; ++j)
        {
            if(s[j] == t[j] && lastt == j)
            {
                std::cout<<"NO\n";
                break;
            }
            if(s[j] == t[j] && lasts == j)
            {
                std::cout<<"YES\n";
                break;
            }
            if(s[j] > t[j])
            {
                std::cout<<"YES\n";
                break;
            }
            if(s[j] < t[j])
            {
                std::cout<<"NO\n";
                break;
            }
        }
    }
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
