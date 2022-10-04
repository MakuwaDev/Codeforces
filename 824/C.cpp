#include <iostream>
#include <vector>

void solve()
{
    int n;
    std::string t;
    std::vector<int> s;
    std::vector<int> in(26, -1);
    std::vector<int> out(26, -1);
    auto getPathEnd = [&](int c)
    {
        int len = 0, cur = c;
        while(in[cur] != -1)
        {
            ++len;
            cur = in[cur];
        }
        return std::make_pair(cur, len);
    };
    std::cin>>n;
    std::cin>>t;
    for(auto x : t)
        s.push_back(x - 'a');
    for(int i = 0; i < n; ++i)
    {
        if(in[s[i]] == -1)
        {
            for(int c = 0; c < 26; ++c)
                if(out[c] == -1)
                {
                    auto [clast, len] = getPathEnd(c);
                    if(clast != s[i] || len == 25)
                    {
                        in[s[i]] = c;
                        out[c] = s[i];
                        break;
                    }
                }
        }
        t[i] = in[s[i]] + 'a';
    }
    std::cout<<t<<"\n";
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
