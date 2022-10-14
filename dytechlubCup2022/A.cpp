#include <iostream>
#include <set>
#include <map>

void solve()
{
    int n, k;
    std::string s, res = "";
    std::map<char, int> mp;
    std::cin >> n >> k;
    std::cin >> s;
    for (auto x : s)
        ++mp[x];
    for (int l = 0; l < k; ++l)
    {
        std::multiset<char> mset;
        for (char c = 'a'; c <= 'y'; ++c)
        {
            if (mset.size() == n / k) break;
            if (mp[c] > 0)
            {
                --mp[c];
                mset.insert(c);
            }
        }
        char mex = 'a';
        while (mset.find(mex) != mset.end())
            ++mex;
        res.push_back(mex);
    }
    std::cout << res << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--)
        solve();
}
