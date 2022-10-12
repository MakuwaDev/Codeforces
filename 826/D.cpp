#include <iostream>
#include <vector>

int cnt = 0;

int step(std::vector<int>& t, int n)
{
    std::vector<int> tmp;
    for (int i = 0; i < n; i += 2)
    {
        if (t[i] == t[i + 1] + 1)
        {
            std::swap(t[i], t[i + 1]);
            ++cnt;
        }
        else if (t[i] + 1 != t[i + 1]) return -1;
    }
    for (int i = 0; i < n; i += 2)
        tmp.push_back(t[i]);
    for (int i = 0; i < tmp.size(); ++i)
        t[i] = tmp[i] / 2 + 1;
    return tmp.size();
}

void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> t(n);
    for (int i = 0; i < n; ++i)
        std::cin >> t[i];
    while (n != 1)
    {
        n = step(t, n);
        if (n == -1)
        {
            std::cout << "-1\n";
            cnt = 0;
            return;
        }
    }
    std::cout << cnt << "\n";
    cnt = 0;
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
