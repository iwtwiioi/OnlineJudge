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
int f[N], n, h, r;
struct dat { int x, y; }a[N];
bool cmp(const dat &a, const dat &b) { return a.x==b.x?a.y<b.y:a.x<b.x; }
int main() {
	int tp;
	read(n); read(tp); read(h); read(r);
	for1(i, 1, r) {
		int x=getint(), y=getint();
		if(y<x) swap(x, y); a[i].x=x, a[i].y=y;
	}
	sort(a+1, a+1+r, cmp);
	a[0].x=-10;
	for1(i, 1, r) {
		if(a[i].x==a[i-1].x && a[i].y==a[i-1].y) continue;
		--f[a[i].x+1]; ++f[a[i].y];
	}
	int sum=0;
	for1(i, 1, n) {
		sum+=f[i];
		printf("%d\n", h+sum);
	}
	return 0;
}

