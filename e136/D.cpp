#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

constexpr int MAXN = 2e5+5;

std::vector<int> graph[MAXN];
std::vector<int> st;
bool used[MAXN];
std::vector<int> hparent;

void init(int v, int h)
{
	st.push_back(v);
	if (int(st.size()) >= h)
		hparent[v] = st[st.size() - h];
	for (auto x : graph[v])
		init(x, h);
	st.pop_back();
}

void dfs(int v)
{
	used[v] = true;
	for (int x : graph[v])
        if (!used[x]) dfs(x);
}

int check(int h, int n)
{
    std::vector<int> order, depth(n);
	std::queue<int> q;
	int v, res = 0;
	hparent.assign(n, -1);
	std::fill(used, used + n, false);
	init(0, h);
	q.push(0);
	while (!q.empty())
    {
		v = q.front();
		q.pop();
		order.push_back(v);
		for (auto x : graph[v])
        {
			q.push(x);
			depth[x] = depth[v] + 1;
		}
	}
	std::reverse(order.begin(), order.end());
	for (auto x : order)
        if (!used[x] && depth[x] > h)
        {
            ++res;
            dfs(hparent[x]);
        }
	return res;
}

int main()
{
	int t;
	std::cin>>t;
	while (t--)
    {
		int n, k, p, low, top, mid, res;
		std::cin>>n>>k;
		for(int i = 0; i <= n; ++i)
            graph[i].clear();
		for (int i = 1; i < n; ++i)
		{
			std::cin>>p;
			--p;
			graph[p].push_back(i);
		}
        low = 1;
        top = n - 1;
		while (low <= top)
		{
			mid = (low + top) / 2;
			if (check(mid, n) <= k)
            {
				res = mid;
				top = mid - 1;
			}
			else
				low = mid + 1;
		}
		std::cout<<res<<"\n";
	}
	return 0;
}
