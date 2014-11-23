#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define for1(i,a,n) for(int i=(a);i<=(n);++i)
#define for2(i,a,n) for(int i=(a);i<(n);++i)
#define for3(i,a,n) for(int i=(a);i>=(n);--i)
#define for4(i,a,n) for(int i=(a);i>(n);--i)
#define CC(i,a) memset(i,a,sizeof(i))
#define read(a) a=getint()
#define print(a) printf("%d", a)
#define dbg(x) cout << (#x) << " = " << (x) << endl
#define printarr2(a, b, c) for1(_, 1, b) { for1(__, 1, c) cout << a[_][__]; cout << endl; }
#define printarr1(a, b) for1(_, 1, b) cout << a[_] << '\t'; cout << endl
inline const long long getint() { long long r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const double max(const double &a, const double &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=100105;
const double eps=1e-8;
struct point { double x, y; }a[N], q;
double sum[N], x[N], d;
int s[N], top, n;
inline double cross(const point& a, const point& b, const point& c) { return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y); }
inline double K(const point& a, const point& b) { return (a.y-b.y)/(a.x-b.x); }
double ifind(const point& pos) {
	int l=1, r=top, lmid, rmid;
	while(r-l>=3) {
		lmid=l+(r-l)/3;
		rmid=r-(r-l)/3;
		double k1=K(a[s[lmid]], pos), k2=K(a[s[rmid]], pos);
		if(k2>k1) l=lmid;
		else r=rmid; 
	}
	double ans=0;
	for1(i, l, r) ans=max(K(pos, a[s[i]]), ans);
	return ans;
}
int main() {
	read(n); read(d);
	for1(i, 1, n) {
		read(sum[i]); read(x[i]);
		sum[i]+=sum[i-1];
		a[i].x=i*d; a[i].y=sum[i-1];
	}
	double ans=0;
	for1(i, 1, n) {
		while(top>1 && cross(a[i], a[s[top]], a[s[top-1]])>=0) --top;
		s[++top]=i;
		q.x=x[i]+i*d; q.y=sum[i];
		ans+=ifind(q);
	}
	printf("%.0lf\n", ans);
	return 0;
}