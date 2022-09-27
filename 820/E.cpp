#include <iostream>

inline long long query(int a, int b)
{
    long long x;
    std::cout<<"? "<<a<<" "<<b<<"\n";
    std::cout.flush();
    std::cin>>x;
    return x;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long n = 2, a, b;
    while(true)
    {
        a = query(1, n);
        if(a == -1)
        {
            std::cout<<"! "<<n  - 1;
            return 0;
        }
        b = query(n, 1);
        if(a != b)
        {
            std::cout<<"! "<<a + b;
            return 0;
        }
        ++n;
    }
}
