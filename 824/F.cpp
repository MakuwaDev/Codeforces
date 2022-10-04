#include <iostream>
#include <set>
#include <vector>
#include <iomanip>

constexpr long double eps = 1e-9;

struct segment
{
    long long init_x, init_y;
    int num;
    long double x, y;
    segment() {}
	segment(int p, int q, int num): init_x(q), init_y(-p), num(num)
	{
		x = init_x;
		y = init_y;
	}
    friend bool operator< (const segment& s1, const segment& s2)
    {
        if(s1.init_x * s2.init_y == s1.init_y * s2.init_x) return s1.num < s2.num;
        return s1.init_x * s2.init_y < s1.init_y * s2.init_x;
    }
    segment operator*= (long double ratio) {x *= ratio; y *= ratio; return *this;}

};

struct point
{
    long double x, y;
    point() {}
    point(int a, int b): x(b), y(a) {}
    point operator+= (const point& v) {x += v.x; y += v.y; return *this;}
    point operator-=(const point& v) {x -= v.x; y -= v.y; return *this;}
	point operator+=(const segment& v) {x += v.x; y += v.y; return *this;}
    point operator-=(const segment& v) {x -= v.x; y -= v.y; return *this;}
};

struct stock
{
    point best_a, best_b;
    std::multiset<segment> segs;
    stock(int a, int b)
    {
        best_a = point(a, 0);
        best_b = point(0, b);
        segment seg1 = segment(a, 0, -2);
        segment seg2 = segment(0, b, -1);
        if(a) segs.insert(seg1);
        if(b) segs.insert(seg2);
    }
    void addSeg(int p, int q, int num)
    {
        segment newSeg = segment(2 * p, 2 * q, num);
        segs.insert(newSeg);
        point shift(p, -q);
        best_a += shift;
        best_b -= shift;
        cut_left();
		cut_down();
    }
    void cut_left()
    {
        while (best_a.x < 0)
        {
			segment l_seg = *segs.begin();
			point newBest_a = best_a;
			newBest_a += l_seg;
			if (newBest_a.x > eps)
			{
				long double ratio = newBest_a.x / l_seg.x;
				segment l_seg_left = l_seg;
				l_seg_left *= ratio;
				segs.erase(segs.find(l_seg));
				segs.insert(l_seg_left);
				newBest_a -= l_seg_left;
				newBest_a.x = std::max(newBest_a.x, (long double)0);
			}
            else segs.erase(segs.begin());
			best_a = newBest_a;
		}
    }
    void cut_down()
    {
        while (best_b.y < 0)
        {
			segment d_seg = *segs.rbegin();
			point newBest_b = best_b;
			newBest_b -= d_seg;

			if (newBest_b.y > eps)
            {
				long double ratio = newBest_b.y / -d_seg.y;
				segment d_seg_left = d_seg;
				d_seg_left *= ratio;
				segs.erase(segs.find(d_seg));
				segs.insert(d_seg_left);
				newBest_b += d_seg_left;
				newBest_b.y = std::max(newBest_b.y, (long double)0);
			}
			else segs.erase(segs.find(d_seg));
			best_b = newBest_b;
		}
    }
    void printBest()
    {
		std::cout << best_a.y << "\n";
	}
};

std::vector<int> p, q;

void solve()
{
    int n, a, b;
    std::cin>>n>>a>>b;
    stock st(a, b);
    p.resize(n);
    q.resize(n);
    for(int i = 0; i < n; ++i)
        std::cin>>p[i];
    for(int i = 0; i < n; ++i)
        std::cin>>q[i];
    for(int i = 0; i < n; ++i)
    {
        st.addSeg(p[i], q[i], i);
        st.printBest();
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout<<std::fixed<<std::setprecision(20);
    int t;
    std::cin>>t;
    while(t--)
        solve();
}
