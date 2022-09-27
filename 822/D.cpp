#include <iostream>
#include <vector>
#include <algorithm>

constexpr int MAXN = (int)2e5+5;

long long health[MAXN];
long long ps[MAXN];

void solve()
{
    int l, r;
    long long n, k, hp, worst, curr;
    std::vector<std::pair<long long, long long>> left;
    std::vector<std::pair<long long, long long>> right;
    std::cin>>n>>k;
    --k;
    for(int i = 0; i < n; i++)
        std::cin >> health[i];
    hp = health[k];
    health[k] = 0;
    ps[0] = 0;
    for(int i = 1; i <= n; i++)
        ps[i] = ps[i - 1] + health[i - 1];
    l = k;
    r = k + 1;
    for (int i = k - 1; i >= 0; i--)
    {
        if (ps[i] <= ps[l] || i == 0)
        {
            worst = curr = 0;
            for (int j = l - 1; j >= i; j--)
            {
                curr += health[j];
                worst = std::min(worst, curr);
            }
            left.push_back({curr, -worst});
            l = i;
        }
    }
    for (int i = k + 2; i <= n; i++)
    {
        if (ps[i] >= ps[r] || i == n)
        {
            worst = curr = 0;
            for (int j = r; j <= i - 1; j++)
            {
                curr += health[j];
                worst = std::min(worst, curr);
            }
            right.push_back({curr, -worst});
            r = i;
        }
    }
    std::reverse(left.begin(), left.end());
    std::reverse(right.begin(), right.end());
    while(true)
    {
        bool possible = false;
        if(!left.empty() && hp >= left.back().second)
        {
            hp += left.back().first;
            left.pop_back();
            possible = true;
        }
        if(!right.empty() && hp >= right.back().second)
        {
            hp += right.back().first;
            right.pop_back();
            possible = true;
        }
        if(left.empty() || right.empty())
        {
            std::cout<<"YES\n";
            return;
        }
        if(!possible)
        {
            std::cout<<"NO\n";
            return;
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
