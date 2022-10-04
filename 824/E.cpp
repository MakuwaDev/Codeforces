#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int n;
std::vector<int> d1;
std::vector<int> d2;

bool check(int point_diff)
{
    int p1 = 0;
    int p2 = point_diff;
    int shift;
    std::multiset<int, std::greater<int>> s1, s2;
    std::vector<int> res, left1, left2;
    for (auto d : d1)
        s1.insert(d);
    for (auto d : d2)
        s2.insert(d);
    auto farthest = [](std::multiset<int, std::greater<int>>& s) {return s.empty() ? -1 : *s.begin(); };
    auto farthest_both = [&]() {return std::max(farthest(s1), farthest(s2)); };
    while (farthest_both() > point_diff)
    {
        bool choose_s1 = farthest(s1) > farthest(s2);
        auto &s_far = choose_s1 ? s1 : s2;
        auto &s_near = choose_s1 ? s2 : s1;
        int val = *s_far.begin();
        int complementary = val - point_diff;
        if (!s_near.count(complementary)) return false;
        s_far.erase(s_far.find(val));
        s_near.erase(s_near.find(complementary));
        if (choose_s1) res.push_back(p1 + val);
        else res.push_back(p2 - val);
    }
    for (auto x : s1)
        left1.push_back(x);
    for (auto x : s2)
        left2.push_back(x);
    std::sort(left1.begin(), left1.end());
    std::sort(left2.begin(), left2.end());
    for (int i = 0; i < left1.size(); ++i)
        if (left1[i] + left2[left2.size() - i - 1] != point_diff) return false;
    for (auto x : left1)
        res.push_back(x);
    std::sort(res.begin(), res.end());
    shift = std::max(-res[0], 0);
    p1 += shift;
    p2 += shift;
    for (auto& x : res)
        x += shift;
    std::cout << "YES\n";
    for (auto x : res)
        std::cout << x << " ";
    std::cout << "\n";
    std::cout << p1 << " " << p2 << "\n";
    return true;
}

void solve()
{
    int dist1;
    std::cin >> n;
    d1.resize(n);
    d2.resize(n);
    for (int i = 0; i < n; ++i)
        std::cin >> d1[i];
    for (int i = 0; i < n; ++i)
        std::cin >> d2[i];
    dist1 = d1[0];
    for (auto dist2 : d2)
    {
        if (check(dist1 + dist2)) return;
        if (check(std::abs(dist1 - dist2))) return;
    }
    std::cout << "NO\n";
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
