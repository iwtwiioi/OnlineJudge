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
#define print(a) printf("%lld", a)
#define dbg(x) cout << (#x) << " = " << (x) << endl
#define printarr(a, n, m) rep(aaa, n) { rep(bbb, m) cout << a[aaa][bbb]; cout << endl; }
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }
typedef long long ll;
#define lc x<<1
#define rc x<<1|1
#define lson l, m, lc
#define rson m+1, r, rc
#define MID (l+r)>>1

const int N=40005, M=3000005;
int n;
struct dat { int x, y, h; }a[N], b[N];
struct nod { ll h, sum; }t[M];
bool cmp(const dat &a, const dat &b) { return a.x==b.x?a.y<a.y:a.x<b.x; }
void pushdown(int x, int m) {
	if(t[x].h) {
		int k=t[x].h; dbg(m);
		if(k>t[lc].h) t[lc].h=k, t[lc].sum=(m-(m>>1))*k; dbg(m-(m>>1)); 
		if(k>t[rc].h) t[rc].h=k, t[rc].sum=(m>>1)*k; dbg(m>>1);
	}
}
void pushup(int x) { t[x].sum=t[lc].sum+t[rc].sum; }
void update(int l, int r, int x, int L, int R, int fix) {
	if(l>r) return;
	pushdown(x, r-l+1);
	if(L<=l && r<=R) {
		if(fix>t[x].h) {
			t[x].h=fix;
			t[x].sum=(r-l+1)*fix;
		}
		return;
	}
	int m=MID;
	if(L<=m) update(lson, L, R, fix); if(m<R) update(rson, L, R, fix);
	pushup(x);
}
ll query(int l, int r, int x, int L, int R) {
	if(l>r) return 0;
	if(L<=l && r<=R) return t[x].sum;
	int m=MID, ret=0;
	if(L<=m) ret+=query(lson, L, R); if(m<R) ret+=query(rson, L, R);
	return ret;
}
int main() {
	read(n);
	for1(i, 1, n) read(a[i].x), read(a[i].y), read(a[i].h);
	sort(a+1, a+1+n, cmp);
	int mx=1;
	for1(i, 1, n) {
		int t=a[i].x-a[i-1].y, t2=a[i].y-a[i].x; b[i].h=a[i].h;
		if(t>0) b[i].x=b[i-1].y+1, b[i].y=b[i].x+t2;
		else if(t<0) b[i].x=b[i-1].y+t, b[i].y=b[i].x+t2;
		else b[i].x=b[i-1].y, b[i].y=b[i].x+t2;
		mx=max(mx, b[i].y);
	}
	//for1(i, 1, n) printf("i=%d \t x=%d \t y=%d \t h=%d\n", i, b[i].x, b[i].y, b[i].h);
	for1(i, 1, n) update(1, mx, 1, b[i].x+1, b[i].y, b[i].h);
	print(t[1].sum);
	return 0;
}

