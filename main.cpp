#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
#define USING_ORDERED_SET 0
#if USING_ORDERED_SET
#include<bits/extc++.h>
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
#endif
template<class T>void umax(T &a,T b){if(a<b)a=b;}
template<class T>void umin(T &a,T b){if(b<a)a=b;}
#ifdef juggernaut
    #define printl(args...) printf(args)
#else
    #define printl(args...) 0
#endif
struct Point{
	double x, y;
	Point(double _x, double _y){
		x = _x;
		y = _y;
	}
	Point(){}
};
struct Line{
	Point p1, p2;
	Point slope;
	Point mid(double dis){
		return Point(p1.x + slope.x * dis, p1.y + slope.y * dis);
	}
	double dist;
	Line(Point _p1, Point _p2){
		p1 = _p1;
		p2 = _p2;
		slope.x = p2.x - p1.x;
		slope.y = p2.y - p1.y;
		dist = slope.x * slope.x + slope.y * slope.y;
	}
	Line(){}
};
inline bool le(double a, double b){
	return a - b < 1e-3;
}
inline double area(Point &a, Point &b, Point &c){
	auto ans = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	if(ans > 0)
		ans = 1;
	if(ans < 0)
		ans = -1;
	return ans;
}
inline bool inter2(double a, double b, double c, double d){
	if(a > b)
		swap(a, b);
	if(c > d)
		swap(c, d);
	return max(a, c) <= min(b, d);
}
inline bool inter(Point &a, Point &b, Point &c, Point &d){
	return inter2(a.x, b.x, c.x, d.x) && inter2(a.y, b.y, c.y, d.y) && (area(a,b,c) * area(a,b,d) <= 0) && (area(c,d,a) * area(c,d,b) <= 0);
}
inline double dist(Point &a, Point b){
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
double near(Line &a, Point &b){
	double l = 0, r = 1;
	int timer = 40;
	while(timer--){
		double m1 = l + (r - l) / 3.0;
		double m2 = r - (r - l) / 3.0;
		if(dist(b, a.mid(m2)) < dist(b, a.mid(m1)))
			l = m1;
		else
			r = m2;
	}
	return dist(b, a.mid(l));
}
double near(Line &a, Line &b){
	if(inter(a.p1, a.p2, b.p1, b.p2))
		return 0;
	return min(min(near(a, b.p1), near(a, b.p2)),min(near(b, a.p1), near(b, a.p2)));		
}
bool check(Line &a, Line &b, Line &c){
	if(le(near(a, b), c.dist))return true;
	if(le(near(a, c), b.dist))return true;
	if(le(near(b, c), a.dist))return true;
	return false;
}
Line a[105];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		Point p1, p2;
		cin >> p1.x >> p1.y >> p2.x >> p2.y;
		a[i] = Line(p1, p2);
	}
	int cnt = 0;
	for(int i = 1; i < n; i++)
		for(int j = i + 1; j < n; j++)
			for(int k = j + 1; k <= n; k++)
				if(check(a[i], a[j], a[k])){
					cnt++;
					//cout << i << ' ' << j << ' ' << k << '\n';
				}
	cout << cnt;
}
