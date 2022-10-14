#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <cassert>

std::mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());

struct node
{
    long long key;
    long long lazy;
    int cnt;
    unsigned int prior;
    node *l;
    node *r;
    node() {}
    node(long long key) : key(key), lazy(0), cnt(1), prior(rng()), l(0), r(0) {}
};

static inline int getCnt(node *t)noexcept
{
    return t ? t->cnt : 0;
}

static inline void updCnt(node *t)noexcept
{
    if (t) t->cnt = getCnt(t->l) + getCnt(t->r) + 1;
}

static inline void modify(node *t, long long delta)noexcept
{
    if (t)
    {
        t->key += delta;
        t->lazy += delta;
    }
}

static inline void down(node *t)noexcept
{
    if (t && t->lazy)
    {
        long long lazy = t->lazy;
        t->lazy = 0;
        if (t->l)
        {
            t->l->key += lazy;
            t->l->lazy += lazy;
        }
        if (t->r)
        {
            t->r->key += lazy;
            t->r->lazy += lazy;
        }
    }
}

void split(node *t, node *&l, node *&r, int key, int add = 0)
{
    if (!t)
    {
        l = r = 0;
        return;
    }
    down(t);
    int cur_key = add + getCnt(t->l);
    if (key <= cur_key)
    {
        split(t->l, l, t->l, key, add);
        r = t;
    }
    else
    {
        split(t->r, t->r, r, key, cur_key + 1);
        l = t;
    }
    updCnt(t);
}

void split(node *t, long long key, node *&l, node *&r)
{
    if (!t)
    {
        l = r = 0;
        return;
    }
    down(t);
    if (t->key <= key)
    {
        split(t->r, key, t->r, r);
        l = t;
    } else
    {
        split(t->l, key, l, t->l);
        r = t;
    }
    updCnt(t);
}

void merge(node *&t, node *l, node *r)
{
    down(l);
    down(r);
    if (!l || !r)
    {
        t = l ? l : r;
    }
    else if (l->prior > r->prior)
    {
        merge(l->r, l->r, r);
        t = l;
    }
    else
    {
        merge(r->l, l, r->l);
        t = r;
    }
    updCnt(t);
}

struct Arrangement
{
    node *root;
    Arrangement() : root(0) {}
    Arrangement(std::vector<long long> vec)
    {
        root = 0;
        std::sort(vec.begin(), vec.end());
        for (auto x: vec)
            merge(root, root, new node(x));
    }
    int size()
    {
        return getCnt(root);
    }
    void incAll(long long delta)
    {
        modify(root, delta);
    }
    void incPrefixRev(int len, long long delta)
    {
        node *l, *r;
        split(root, l, r, len);
        modify(l, delta);
        merge(root, r, l);
    }
    void incSuffixRev(int len, long long delta)
    {
        node *l, *r;
        int C = size();
        split(root, l, r, C - len);
        modify(r, delta);
        merge(root, r, l);
    }
    void insert(long long val)
    {
        node *l, *r;
        split(root, val - 1, l, r);
        modify(r, 1);
        merge(root, l, new node(val));
        merge(root, root, r);
    }
    int cnt_upper_bound(long long val)
    {
        int ans = 0;
        auto t = root;
        while (t)
        {
            down(t);
            if (t->key > val) t = t->l;
            else
            {
                ans += getCnt(t->l) + 1;
                t = t->r;
            }
        }
        return ans;
    }
    long long getFirst()
    {
        assert(root);
        auto t = root;
        while (t->l)
        {
            down(t);
            t = t->l;
        }
        return t->key;
    }
};

void solve()
{
    struct Query
    {
        long long k;
        int m;
        int id;
        long long ans;
    };
    int n, q;
    long long d;
    std::string s;
    std::vector<Query> queries;
    std::vector<long long> immovable;
    std::cin >> n >> d >> q;
    std::vector<long long> a(n);
    for (auto &x: a)
        std::cin >> x;
    std::cin >> s;
    for (int i = 0; i < n; i++)
        if (s[i] == '0') a[i] = -a[i];
    for (int i = 0; i < q; i++)
    {
        int k, m;
        std::cin >> k >> m;
        queries.push_back({k, m, i, 0});
    }
    for (auto x: a)
        if (x < 0) immovable.push_back(-x);
    {
        std::vector<long long> new_a;
        for (auto x: a)
        {
            if (x < 0) continue;
            int cnt = std::upper_bound(immovable.begin(), immovable.end(), x) - immovable.begin();
            new_a.push_back(x - cnt);
        }
        a = new_a;
    }
    Arrangement arrangement({a[0]});
    long long op = 0;
    auto process_query = [&](Query &query, int i)
    {
        int C = arrangement.size();
        long long need = query.k - op;
        long long big = need / C;
        int small = need - big * C;
        arrangement.incAll(big * (C - 1 + d));
        arrangement.incPrefixRev(small, C - 1 + d);
        long long lo = 0, hi = 3e18;
        while (hi - lo > 1)
        {
            long long mid = (lo + hi) / 2;
            long long L = mid;
            int m = query.m;
            int cnt = std::upper_bound(immovable.begin(), immovable.end(), L) - immovable.begin();
            L -= cnt;
            m -= cnt;
            cnt = std::upper_bound(i + a.begin(), a.end(), L) - a.begin() - i;
            L -= cnt;
            m -= cnt;
            if (m <= arrangement.cnt_upper_bound(L)) hi = mid;
            else lo = mid;
        }
        query.ans = hi;
        arrangement.incSuffixRev(small, -(C - 1 + d));
        arrangement.incAll(-big * (C - 1 + d));
    };
    std::sort(queries.begin(), queries.end(), [](const Query &x, const Query &y) {return x.k < y.k;});
    auto current_query = queries.begin();
    for (int i = 1; i < (int)a.size(); i++)
    {
        long long gap = a[i] - arrangement.getFirst();
        int C = arrangement.size();
        long long h = (gap - 1) / (C - 1 + d);
        while (current_query != queries.end() && current_query->k <= op + h * C)
            process_query(*(current_query++), i);
        arrangement.incAll(h * (C - 1 + d));
        arrangement.insert(a[i]);
        op += h * C;
    }
    while (current_query != queries.end())
        process_query(*(current_query++), a.size());
    std::sort(queries.begin(), queries.end(), [](const Query &x, const Query &y) {return x.id < y.id;});
    for (auto &query: queries)
        std::cout << query.ans << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
}
