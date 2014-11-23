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

const int N=400010;
int p[N], vis[N], ihead[N], cnt, tot, n, m, ans[N], q[N], des[N], d;
struct ED { int to, next; }e[N];
inline void add(const int &u, const int &v) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v;
	e[++cnt].next=ihead[v]; ihead[v]=cnt; e[cnt].to=u;
}
const int ifind(const int &x) { return x==p[x]?x:p[x]=ifind(p[x]); }
inline void update(const int &u) {
	int fu=ifind(u), fv;
	for(int i=ihead[u]; i; i=e[i].next) if(vis[e[i].to]) {
		fv=ifind(e[i].to);
		if(fv!=fu) { p[fv]=fu; --tot; }
	}
}

int main() {
	read(n); read(m);
	int x, y;
	rep(i, n) p[i]=i;
	for1(i, 1, m) {
		read(x); read(y);
		add(x, y);
	}
	read(d);
	for1(i, 1, d) {
		read(q[i]);
		des[q[i]]=1;
	}
	rep(i, n) if(!des[i]) {
		++tot;
		update(i);
		vis[i]=1;
	}
	ans[d+1]=tot;
	for3(i, d, 1) {
		++tot;
		update(q[i]);
		vis[q[i]]=1;
		ans[i]=tot;
	}
	for1(i, 1, d+1) printf("%d\n", ans[i]);
	return 0;
}

