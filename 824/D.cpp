#include <iostream>
#include <vector>
#include <map>

constexpr int MAXN = 1e3+3;
constexpr int MAXK = 20;

std::vector<std::vector<int>> feature(MAXN, std::vector<int>(MAXK));
std::map<std::vector<int>, int> mp;

std::vector<int> middlecard(std::vector<int>& a, std::vector<int>& b)
{
    int k = a.size();
    std::vector<int> res(k);
    for(int i = 0; i < k; ++i)
        res[i] = (6 - (a[i] + b[i])) % 3;
    return res;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k, res = 0;
    std::cin>>n>>k;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < k; ++j)
            std::cin>>feature[i][j];
    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j)
            ++mp[middlecard(feature[i], feature[j])];
    for(int i = 0; i < n; ++i)
        res += (mp[feature[i]] * (mp[feature[i]] - 1)) / 2;
    std::cout<<res;
}
