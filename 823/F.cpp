#include <iostream>

constexpr int MAXN = 5005;
constexpr int MAXK = 8;

int n, k;
int p[MAXN];
int pos[MAXN];
int dp[MAXN][1 << MAXK];
int t[MAXN];

int sum(int r)
{
    int ans = 0;
    for(; r >= 0; r = (r & r + 1) - 1)
        ans += t[r];
    return ans;
}

void inc(int i, int d)
{
    for(; i < MAXN; i |= i + 1)
        t[i] += d;
}

int inv(int mn, int mask, int x)
{
    int ans = 0;
    for(int i = 0; i < k; ++i)
        if((mask & (1 << i)) && pos[x] < pos[mn + 1 + i])
            ++ans;
    ans += sum(MAXN - 1) - sum(pos[x]);
    return ans;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> n >> k;
    for(int i = 0; i < n; ++i)
    {
        std::cin >> p[i];
        p[i]--;
        pos[p[i]] = i;
    }
    for(int mn = 0; mn <= n; ++mn)
        for(int mask = 0; mask < (1 << k); ++mask)
            dp[mn][mask] = (int)1e9;
    dp[0][0] = 0;
    for(int mn = 0; mn < n; ++mn)
    {
        for(int mask = 0; mask < (1 << std::min(k, n - mn - 1)); ++mask)
        {
            for(int i = 0; i < std::min(k, n - mn - 1); ++i)
                if((mask & (1 << i)) == 0)
                    dp[mn][mask + (1 << i)] = std::min(dp[mn][mask + (1 << i)], dp[mn][mask] + inv(mn, mask, mn + 1 + i));
            int mn2 = mn, mask2 = mask;
            ++mn2;
            while(mask2 % 2)
            {
                ++mn2;
                mask2 /= 2;
            }
            mask2 /= 2;
            dp[mn2][mask2] = std::min(dp[mn2][mask2], dp[mn][mask] + inv(mn, mask, mn));
        }
        inc(pos[mn], 1);
    }
    std::cout << dp[n][0];
}
