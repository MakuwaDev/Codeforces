#include <iostream>
#include <vector>

long long gcd(long long a, long long b)
{
    long long h;
    while(b != 0)
    {
        h = b;
        b = a % b;
        a = h;
    }
    return a;
}

long long lcm(long long a, long long b)
{
    long long g = gcd(a, b);
    return a * b / g;
}

void solve()
{
    long long n;
    std::cin>>n;
    std::vector<int> a(n + 2, 1);
    std::vector<int> b(n + 2, 1);
    for(int i = 1; i <= n; ++i)
        std::cin>>a[i];
    for(int i = 1; i <= n + 1; ++i)
        b[i] = lcm(a[i], a[i - 1]);
    for(int i = 1; i <= n; ++i)
        if(gcd(b[i], b[i + 1]) != a[i])
        {
            std::cout<<"NO\n";
            return;
        }
    std::cout<<"YES\n";
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
