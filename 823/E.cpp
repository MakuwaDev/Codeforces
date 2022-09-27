#include <iostream>
#include <vector>

constexpr int MAXN = 5e5+5;
constexpr int MAXA = 1e6+6;

std::vector<int> divisors[MAXA];
int tab[MAXN];
std::vector<int> pos[MAXA];
int gr_lf[MAXN];
int gr_rg[MAXN];
int less_lf[MAXN];
int less_rg[MAXN];
int ind[MAXA];

void solve()
{
    int n;
    long long ans = 0;
    std::vector<int> st;
    std::cin>>n;
    for(int i = 0; i < n; ++i)
    {
        std::cin>>tab[i];
        pos[tab[i]].push_back(i);
    }
    for(int i = 0; i < n; i++)
    {
        while(!st.empty() && tab[st.back()] < tab[i])
            st.pop_back();
        gr_lf[i] = (st.empty() ? -1 : st.back());
        st.push_back(i);
    }
    st.clear();
    for(int i = n - 1; i >= 0; --i)
    {
        while(!st.empty() && tab[st.back()] <= tab[i])
            st.pop_back();
        gr_rg[i] = (st.empty() ? n: st.back());
        st.push_back(i);
    }
    st.clear();
    for(int i = 0; i < n; ++i)
    {
        while(!st.empty() && tab[st.back()] >= tab[i])
            st.pop_back();
        less_lf[i] = (st.empty() ? -1 : st.back());
        st.push_back(i);
    }
    st.clear();
    for(int i = n - 1; i >= 0; --i)
    {
        while(!st.empty() && tab[st.back()] >= tab[i])
            st.pop_back();
        less_rg[i] = (st.empty() ? n : st.back());
        st.push_back(i);
    }
    for(int i = 0; i < n; i++)
    {
        for(int x : divisors[tab[i]])
        {
            if(ind[x] >= 1)
            {
                int j = pos[x][ind[x] - 1];
                if(j > gr_lf[i] && less_rg[j] > i) ans += (long long)(j - std::max(gr_lf[i], less_lf[j])) * (long long)(std::min(gr_rg[i], less_rg[j]) - i);
            }
            if(ind[x] < pos[x].size())
            {
                int j = pos[x][ind[x]];
                if(j < gr_rg[i] && less_lf[j] < i) ans += (long long)(i - std::max(std::max(gr_lf[i], less_lf[j]), ind[x] >= 1 ? pos[x][ind[x] - 1] : -1)) * (long long)(std::min(gr_rg[i], less_rg[j]) - j);
            }
        }
        ++ind[tab[i]];
    }
    std::cout<<ans<<"\n";
    for(int i = 0; i < n; i++)
    {
        pos[tab[i]].clear();
        gr_lf[i] = gr_rg[i] = less_lf[i] = less_rg[i] = 0;
        ind[tab[i]] = 0;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    for(int i = 1; i < MAXA; ++i)
        for(int j = i; j < MAXA; j += i)
            divisors[j].push_back(i);
    int t;
    std::cin>>t;
    while(t--)
        solve();
}
