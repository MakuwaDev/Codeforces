

    #include <cstdio>
    #include <cstring>
    #include <vector>

    constexpr int MAXN = 505;
    constexpr int MOD = 1e9 + 7;

    int p[MAXN];
    char s[MAXN], t[MAXN];
    int f[MAXN], g[MAXN];
    int n, m, tot;

    inline int addv(int x,int y){
    	int s=x+y;
    	if(s>=MOD) s-=MOD;
    	return s;
    }
    inline int subv(int x,int y){
    	int s=x-y;
    	if(s<0) s+=MOD;
    	return s;
    }
    inline void add(int&x,int y){
    	x=addv(x,y);
    	return ;
    }
    inline void sub(int&x,int y){
    	x=subv(x,y);
    	return ;
    }

    void init()
    {
        scanf("%s", s + 1);
        scanf("%s", t + 1);
        n = strlen(s + 1);
        m = strlen(t + 1);
        tot = 0;
        for(int i = 1; i + m - 1 <= n; ++i)
        {
            bool flag = true;
    		for(int j = 1; j <= m; j++)
    			if(s[i + j - 1] != t[j]) flag = 0;
    		if(flag) p[++tot] = i;
        }
        return;
    }

    void solve()
    {
        memset(f, 0x3f, sizeof(f));
        memset(g, 0, sizeof(g));
        p[0] = -MAXN;
        f[0] = 0;
        g[0] = 1;
        p[++tot] = n + m;
        for(int i = 0; i < tot; ++i)
        {
    		int j = i + 1;
    		while(j <= tot && p[j] <= p[i] + m - 1)
                ++j;
    		for(int k = j; p[j] + m - 1 >= p[k] && k <= tot; ++k)
    		{
    			if(f[i] + 1 < f[k])
    			{
    				f[k] = f[i] + 1;
    				g[k] = g[i];
    			}
    			else if(f[i] + 1 ==f[k]) add(g[k], g[i]);
    		}
    	}
    	printf("%d %d\n",f[tot] - 1,g[tot]);
    }

    int main()
    {
        int t;
        scanf("%d", &t);
        while(t--)
        {
            init();
            solve();
        }
    }
