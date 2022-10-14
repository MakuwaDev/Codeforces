#include <iostream>

long long sqrt(long long x)
{
    long long low = 0, top = 1004000000, mid;
    while(top > low)
    {
        mid = (top + low) / 2;
        if(mid * mid > x) top = mid;
        else low = mid + 1;
    }
    return low - 1;
}

void solve()
{
    long long l, r, sql, sqr, res = 0;
    std::cin>>l>>r;
    sql = sqrt(l);
    sqr = sqrt(r);
    if (sql == sqr)
    {
        for (int i = 0; i < 3; i++)
            if (l <= sql * (sql + i) && sql * (sql + i) <= r) ++res;
    }
    else
    {
        res = (sqr - sql - 1) * 3;
        for (int i = 0; i < 3; i++)
        {
            if (l <= sql * (sql + i) && sql * (sql + i) <= r) ++res;
            if (l <= sqr * (sqr + i) && sqr * (sqr + i) <= r) ++res;
        }
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
