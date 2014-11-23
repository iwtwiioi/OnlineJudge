#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
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

const int N=100005;
int hash[N], n, line, cnt, ans, c[N];
struct ND { int x, y; }nd[N];
struct seg { int x, y, r, k; }s[N*10]; //这里的k别有用心，按k排序的话，刚好可以将完结的竖条先剪掉，然后再将横条的统计，然后再加上y轴的竖条。。太赞了
inline const bool cmp1(const ND &a, const ND &b) { return a.x==b.x ? a.y<b.y : a.x<b.x; } //竖
inline const bool cmp2(const ND &a, const ND &b) { return a.y==b.y ? a.x<b.x : a.y<b.y; } //横
inline const bool cmp3(const seg &a, const seg &b) { if(a.y==b.y) return a.k<b.k; return a.y<b.y; }
inline const int ifind(const int &x) { return lower_bound(hash+1, hash+1+line, x)-hash; }
inline void add(const int &x, const int &r, const int &y, const bool &d) {
	if(d) { //竖 r下边的，y上边的
		int fx=ifind(x);
		s[++cnt].x=fx; s[cnt].y=r; s[cnt].k=1;
		s[++cnt].x=fx; s[cnt].y=y; s[cnt].k=-1;
	}
	else { s[++cnt].x=ifind(x); s[cnt].r=ifind(r); s[cnt].y=y; }
}
void build() {
	sort(nd+1, nd+1+n, cmp1);
	for2(i, 1, n) if(nd[i].x==nd[i+1].x) add(nd[i].x, nd[i].y, nd[i+1].y, 1);
	sort(nd+1, nd+1+n, cmp2);
	for2(i, 1, n) if(nd[i].y==nd[i+1].y) add(nd[i].x, nd[i+1].x, nd[i].y, 0);
}
inline int sum(int x) { int ret=0; for(; x; x-=(x&-x)) ret+=c[x]; return ret; }
inline void update(int x, const int &y) { for(; x<=line; x+=(x&-x)) c[x]+=y; }
void getans() {
	for1(i, 1, cnt)
		if(!s[i].k) ans+=sum(s[i].r-1)-sum(s[i].x);
		else update(s[i].x, s[i].k);
}
int main() {
	read(n);
	for1(i, 1, n) { read(nd[i].x); read(nd[i].y); hash[i]=nd[i].x; }
	sort(hash+1, hash+1+n); hash[n+1]=~0u>>1;
	for1(i, 1, n) if(hash[i]!=hash[i+1]) hash[++line]=hash[i];
	build();
	sort(s+1, s+1+cnt, cmp3);
	getans();
	print(n+ans);
	return 0;
}

