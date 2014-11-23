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
const int N=10005, Q=90000, oo=~0u>>1;
int n, st, en, mn[Q];
int ans;
struct dat { int x, y, w; }a[N];
const bool cmp(const dat &x, const dat &y) { return x.x<y.x; }
void update(int x, const int &c) {
	for(; x<=en; x+=x&-x) mn[x]=min(mn[x], c);
}
void sum(int x) {
	int ret=oo;
	for(; x; x-=x&-x) ret=min(ret, mn[x]);
	return ret;
}
int main() {
	read(n); read(st); read(en);
	for1(i, 1, n) read(a[i].x), read(a[i].y), read(a[i].w);
	sort(a+1, a+1+n, cmp);
	memset(mn, 0x7f, sizeof(int)*(en+10));
	for1(i, 1, n) {
		if(a[i].x<=st) ans=0; else ans=query(st, en, 1, a[i].x-1, a[i].y);
		if(ans!=oo) update(a[i].y, ans+a[i].w);
	}
	ans=query(st, en, 1, en, en);
	if(ans==oo) puts("-1");
	else printf("%d", ans);
	return 0;
}

