        #include <iostream>
         
        constexpr int MAXN = 110;
         
        int dp[MAXN][MAXN][2]; // dp[even][odd][sum % 2]
        bool was[MAXN][MAXN][2];
         
        int go(int even, int odd, int parity)
        {
            if(even + odd == 0) return parity == 0;
            int& res = dp[even][odd][parity];
            if(was[even][odd][parity]) return res;
            was[even][odd][parity] = true;
            if(even > 0) res |= 1 - go(even - 1, odd, (parity + odd + 1) % 2);
            if(odd > 0) res |= 1 - go(even, odd - 1, (parity + odd + 1) % 2);
            return res;
        }
         
        void solve()
        {
            int n, odd = 0, even = 0, k;
            std::cin>>n;
            for(int i = 0; i < n; ++i)
            {
                std::cin>>k;
                if(k % 2 == 0) ++even;
                else ++odd;
            }
            k = go(even, odd, 0);
            std::cout<<(k ? "Alice" : "Bob")<<"\n";
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
