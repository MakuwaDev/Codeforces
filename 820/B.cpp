#include <iostream>
#include <algorithm>

void solve()
{
    int n, i;
    std::string s, res;
    std::cin>>n;
    std::cin>>s;
    i = n - 1;
    while(i >= 0)
    {
        if(s[i] != '0')
        {
            res.push_back(s[i] - '0' + 'a' - 1);
            --i;
        }
        else
        {
            int number = std::stoi(s.substr(i - 2, 2));
            res.push_back(number + 'a' - 1);
            i -= 3;
        }
    }
    std::reverse(res.begin(), res.end());
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
