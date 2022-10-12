#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

void solve()
{
    int n, k = 0, root, v;
    std::vector<int> b;
    std::vector<std::vector<int>> graph;
    std::vector<int> q;
    std::cin>>n;
    b.resize(n + 1);
    graph.resize(n + 2);
    for(int i = 1; i <= n; ++i)
    {
        std::cin>>b[i];
        if(b[i] > i) k = i;
    }
    for(int i = 1; i<= n; ++i)
        graph[b[i]].push_back(i);
    root = graph[0].size() ? 0 : n + 1;
    q = {root};
    for(int i = 0; i < q.size(); ++i)
    {
        v = q[i];
        std::sort(graph[v].begin(), graph[v].end(), [&] (int a, int b) {return graph[a].size() < graph[b].size();});
        for(auto x : graph[v])
            q.push_back(x);
    }
    std::cout<<k<<"\n";
    for(int i = 1; i < q.size(); ++i)
        std::cout<<q[i]<<" ";
    std::cout<<"\n";
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
