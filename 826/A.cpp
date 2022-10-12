#include <iostream>
#include <string>

void solve()
{
    std::string a, b;
    std::cin>>a>>b;
    if(a[a.size() - 1] != b[b.size() - 1])
    {
        if(a[a.size() - 1] == 'L') std::cout<<">\n";
        else if(b[b.size() - 1] == 'L') std::cout<<"<\n";
        else if(a[a.size() - 1] == 'M') std::cout<<">\n";
        else if(b[b.size() - 1] == 'M') std::cout<<"<\n";
    }
    else
    {
        if(a[a.size() - 1] == 'L')
        {
            if(a.size() > b.size()) std::cout<<">\n";
            else if(a.size() == b.size()) std::cout<<"=\n";
            if(a.size() < b.size()) std::cout<<"<\n";
        }
        else if(a[a.size() - 1] == 'S')
        {
            if(a.size() > b.size()) std::cout<<"<\n";
            else if(a.size() == b.size()) std::cout<<"=\n";
            if(a.size() < b.size()) std::cout<<">\n";
        }
        else std::cout<<"=\n";
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
