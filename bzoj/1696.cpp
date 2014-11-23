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
#define dbg(x) cout << #x << " = " << x << endl
#define printarr(a, n, m) rep(aaa, n) { rep(bbb, m) cout << a[aaa][bbb]; cout << endl; }
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=10005;
struct dat { int x, y; }a[N];
bool cmpx(const dat &a, const dat &b) { return a.x<b.x; }
bool cmpy(const dat &a, const dat &b) { return a.y<b.y; }
int n, ans1, ans2;
bool check(int x, int y) {
	for1(i, 1, n) if(a[i].x==x && a[i].y==y) return 0;
	return 1;
}
int main() {
	read(n);
	for1(i, 1, n) read(a[i].x), read(a[i].y);
	if(n&1) {
		int x, y;
		sort(a+1, a+1+n, cmpx); x=a[(n>>1)+1].x;
		sort(a+1, a+1+n, cmpy); y=a[(n>>1)+1].y;
		if(check(x, y)) {
			for1(i, 1, n) ans1+=abs(x-a[i].x)+abs(y-a[i].y);
			ans2=1;
		}
		else {
			static int tp[4];
			CC(tp, 0);
			int fx[]={x+1, x-1, x, x}, fy[]={y, y, y-1, y+1}; ans1=~0u>>1;
			for1(i, 1, n) rep(j, 4) tp[j]+=abs(fx[j]-a[i].x)+abs(fy[j]-a[i].y);
			rep(j, 4) if(ans1>tp[j]) ans1=tp[j], ans2=1; else if(ans1==tp[j]) ++ans2;
		}
	}
	else {
		int x, y, xx, yy;
		sort(a+1, a+1+n, cmpx); x=a[(n>>1)].x; xx=a[(n>>1)+1].x;
		sort(a+1, a+1+n, cmpy); y=a[(n>>1)].y; yy=a[(n>>1)+1].y;
		ans2=(xx-x+1)*(yy-y+1);
		for1(i, 1, n) {
			if(a[i].x>=x && a[i].x<=xx && a[i].y>=y && a[i].y<=yy) --ans2;
			ans1+=abs(x-a[i].x)+abs(y-a[i].y);
		}
	}
	printf("%d %d", ans1, ans2);
	return 0;
}

