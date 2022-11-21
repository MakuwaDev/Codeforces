#include <iostream>

char t[8][8];

bool checkrow(int i)
{
    for(int j = 0; j < 8; ++j)
        if(t[i][j] != 'R') return false;
    return true;
}

bool checkline(int i)
{
    for(int j = 0; j < 8; ++j)
        if(t[j][i] != 'B') return false;
    return true;
}

void solve()
{
    int lines = 0, rows = 0;
    std::string s;
    for(int i = 0; i < 8; ++i)
    {
        std::cin>>s;
        for(int j = 0; j < 8; ++j)
            t[i][j] = s[j];
    }
    for(int i = 0; i < 8; ++i)
        if(checkrow(i)) ++rows;
    for(int i = 0; i < 8; ++i)
        if(checkline(i)) ++lines;
    if(lines > 0) std::cout<<"B\n";
    else std::cout<<"R\n";
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
