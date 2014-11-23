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

#define lc x<<1
#define rc x<<1|1
#define MID (l+r)>>1
#define lson l, m, lc
#define rson m+1, r, rc
const int N=200005;
int s[N*10], L, R, n;
bool add[N*10];
inline void pushup(const int &x) { s[x]=s[lc]+s[rc]; }
inline void pushdown(const int &x, const int &m) {
	if(add[x]) {
		add[lc]^=1; add[rc]^=1;
		s[lc]=(m-(m>>1))-s[lc];
		s[rc]=(m>>1)-s[rc];
		add[x]=0;
	}
}
void update(const int &l, const int &r, const int &x) {
	if(L<=l && r<=R) { add[x]^=1; s[x]=r-l+1-s[x]; return; }
	pushdown(x, r-l+1);
	int m=MID;
	if(L<=m) update(lson); if(m<R) update(rson);
	pushup(x);
}
int query(const int &l, const int &r, const int &x) {
	if(L<=l && r<=R) return s[x];
	pushdown(x, r-l+1);
	int m=MID, ret=0;
	if(L<=m) ret+=query(lson); if(m<R) ret+=query(rson);
	pushup(x);
	return ret;
}
int main() {
	read(n);
	int m=getint(), cs;
	while(m--) {
		read(cs); read(L); read(R);
		if(!cs) update(1, n, 1);
		else printf("%d\n", query(1, n, 1));
	}	
	return 0;
}

