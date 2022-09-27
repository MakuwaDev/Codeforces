#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>

void solve()
{
    int n, first, last, kurwa1, kurwan;
    std::vector<int> indexes[26];
    std::vector<int> res;
    std::string s;
    std::cin >> s;
    n = s.size();
    for (int i = 0; i < n; ++i)
        indexes[s[i] - 'a'].push_back(i + 1);
    first = s[0] - 'a';
    last = s[s.size() - 1] - 'a';
    kurwa1 = 1;
    kurwan = n;
    if (first > last)
    {
        std::swap(first, last);
        std::swap(kurwa1, kurwan);
    }
    res.push_back(kurwa1);
    for (int i = first; i <= last; ++i)
        for (auto x : indexes[i])
            if(x != n && x != 1) res.push_back(x);
    res.push_back(kurwan);
    if(res[0] == n) std::reverse(res.begin(), res.end());
    std::cout << std::abs(first - last) << " " << res.size() << "\n";
    for (auto x : res)
        std::cout << x << " ";
    std::cout << "\n";
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
