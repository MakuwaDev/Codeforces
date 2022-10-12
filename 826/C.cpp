#include <iostream>
#include <vector>

void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> t(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> t[i];
    for (int i = 1; i <= n; ++i)
        t[i] = t[i] + t[i - 1];
    for (int length = 1; length <= n; ++length)
        for (int start = 1; start + length - 1 <= n; ++start)
        {
            int x = t[start + length - 1] - t[start - 1];
            bool czy = true;
            int i = 1;
            int j = 1;
            while (j < start)
            {
                if (j - i + 1 > length)
                {
                    czy = false;
                    break;
                }
                    if (t[j] - t[i - 1] == x)
                    {
                        i = j + 1;
                        j = i;
                    }
                    else if (t[j] - t[i - 1] == x)
                    {
                        czy = false;
                        break;
                    }
                    else ++j;
            }
            if (i != j)
                if (t[j - 1] - t[i - 1] != x)czy = false;
            if (!czy) continue;
            i = start + length;
            j = i;
            while (j <= n)
            {
                if (j - i + 1 > length)
                {
                    czy = false;
                    break;
                }
                if (t[j] - t[i - 1] == x)
                {
                    i = j + 1;
                    j = i;
                }
                else if (t[j] - t[i - 1] >= x)
                {
                    czy = false;
                    break;
                }
                else ++j;
            }
            if (i != j)
                if (t[j - 1] - t[i - 1] != x)czy = false;
            if (!czy) continue;
            std::cout << length << "\n";
            return;
        }
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
