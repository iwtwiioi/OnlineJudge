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
inline const long long getint() { long long r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

#define lc x<<1
#define rc x<<1|1
#define MID (l+r)>>1
#define lson l, m, lc
#define rson m+1, r, rc
const int N=200005;
long long s[N*10], L, R, fix, who, n, p;
int add1[N*10], add2[N*10];
inline void pushup(const int &x) { s[x]=(s[lc]+s[rc])%p; }
inline void pushdown(const int &x, const int &m) {
	if(m==1) return;
	long long mf=add2[x], af=add1[x]; add1[x]=0; add2[x]=1;
	s[lc]=( (s[lc]*mf) + ((m-(m>>1))*af) )%p;
	s[rc]=( (s[rc]*mf) + ((m>>1)*af) )%p;
	add1[lc]=(af+(add1[lc]*mf))%p;
	add1[rc]=(af+(add1[rc]*mf))%p;
	add2[lc]=(mf*add2[lc])%p;
	add2[rc]=(mf*add2[rc])%p;
}
void build(const int &l, const int &r, const int &x) {
	if(l==r) { read(s[x]); s[x]%=p; add2[x]=1; return; }
	int m=MID;
	build(lson); build(rson);
	pushup(x); add2[x]=1;
}
void update(const int &l, const int &r, const int &x) {
	pushdown(x, r-l+1);
	if(L<=l && r<=R) { 
		if(who) add1[x]=(add1[x]+fix)%p, s[x]=(s[x]+((r-l+1)*fix)%p)%p; 
		else add2[x]=(fix*add2[x])%p, s[x]=(s[x]*fix)%p; 
		return; 
	}
	int m=MID;
	if(L<=m) update(lson); if(m<R) update(rson);
	pushup(x);
}
int query(const int &l, const int &r, const int &x) {
	pushdown(x, r-l+1);
	if(L<=l && r<=R) return s[x];
	int m=MID, ret=0;
	if(L<=m) ret+=query(lson); if(m<R) ret+=query(rson);
	pushup(x);
	return ret%p;
}
int main() {
	read(n); read(p);
	build(1, n, 1);
	int m=getint(), cs;
	while(m--) {
		read(cs); read(L); read(R);
		if(cs==1) {
			read(fix); who=0;
			update(1, n, 1);
		}
		else if(cs==2) {
			read(fix); who=1;
			update(1, n, 1);
		}
		else printf("%d\n", query(1, n, 1));
	}	
	return 0;
}

