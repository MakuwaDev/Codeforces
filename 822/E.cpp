#include <iostream>

constexpr int MAXN = 355;

int diagonal[MAXN];
int board[MAXN][MAXN];

void solve()
{
    int n;
    std::cin>>n;
    for(int i = 0; i < n; ++i)
        std::cin>>diagonal[i];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            board[i][j] = (i * j) % n;
    for(int i = 0; i < n; ++i)
    {
        int add = (diagonal[i] - board[i][i] + n) % n;
        for(int j = 0; j < n; ++j)
            board[i][j] = (board[i][j] + add) % n;
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
            std::cout<<board[i][j]<<" ";
        std::cout<<"\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
