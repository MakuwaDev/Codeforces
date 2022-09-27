#include <iostream>
#include <vector>

void solve()
{
    std::string s;
    std::cin >> s;
    int n = s.size();
    std::vector<int> a(n);
    std::vector<int> mn(n + 1, 9);
    for(int i = 0; i < n; i++)
        a[i] = int(s[i] - '0');
    for(int i = n - 1; i >= 0; i--)
        mn[i] = std::min(mn[i + 1], a[i]);
    std::vector<int> buff(10, 0);
    std::string ans = "";
    std::string t = "0123456789";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < mn[i]; j++)
            while(buff[j])
            {
                --buff[j];
                ans.push_back(t[j]);
            }
        if(a[i] == mn[i]) ans += t[a[i]];
        else ++buff[std::min(9, a[i] + 1)];
    }
    for(int j = 0; j < 10; j++)
        while(buff[j])
        {
            buff[j]--;
            ans += t[j];
        }
    std::cout << ans << "\n";
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
