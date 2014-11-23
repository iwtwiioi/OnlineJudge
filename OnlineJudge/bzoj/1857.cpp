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
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const double eps=1e-3;
int ax, ay, bx, by, cx, cy, dx, dy;
double P, Q, R;
double dis(double x1, double y1, double x2, double y2) { return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)); }
double cal(double x, double y) {
	double x1, x2, y1, y2, lx=cx, ly=cy, rx=dx, ry=dy;
	while(abs(rx-lx)>eps || abs(ry-ly)>eps) {
		x1=lx+(rx-lx)/3;	y1=ly+(ry-ly)/3;
		x2=lx+(rx-lx)/3*2;	y2=ly+(ry-ly)/3*2;
		double d1=dis(x1, y1, x, y)/R+dis(x1, y1, dx, dy)/Q;
		double d2=dis(x2, y2, x, y)/R+dis(x2, y2, dx, dy)/Q;
		if(d1<d2) rx=x2, ry=y2;
		else lx=x1, ly=y1;
	}
	return dis(x, y, ax, ay)/P+dis(lx, ly, x, y)/R+dis(lx, ly, dx, dy)/Q;
}
int main() {
	cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy >> P >> Q >> R;
	double x1, x2, y1, y2, lx=ax, ly=ay, rx=bx, ry=by;
	while(abs(rx-lx)>eps || abs(ry-ly)>eps) {
		x1=lx+(rx-lx)/3;	y1=ly+(ry-ly)/3;
		x2=rx-(rx-lx)/3;	y2=ry-(ry-ly)/3;
		double d1=cal(x1, y1), d2=cal(x2, y2);
		if(d1<d2) rx=x2, ry=y2;
		else lx=x1, ly=y1;
	}
	printf("%.2lf", cal(lx, ly));
	return 0;
}