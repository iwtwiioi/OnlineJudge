#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define dbg(x) cout << #x << "=" << x << endl
#define read(x) x=getint()
#define print(x) printf("%d", x)
#define lc x<<1
#define rc x<<1|1
#define lson l, m, lc
#define rson m+1, r, rc
#define MID (l+r)>>1

const int oo=~0u>>1;
inline int getint() { char c; int ret=0, k=1; for(c=getchar(); c<'0' || c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) ret=ret*10+c-'0'; return k*ret; }
const int N=30010, M=100005;
int ihead[N], inext[M], to[M], cnt, n, m;
int top[N], son[N], fa[N], dep[N], sz[N], id[N], a[N], b[N], tot;
int L, R, key;
struct node { int mx, sum; }t[N*50];
//inline int max(const int& a, const int &b) { if(a>b) return a; return b; }
inline void pushup(const int &x) { t[x].mx=max(t[lc].mx, t[rc].mx); t[x].sum=t[lc].sum+t[rc].sum; }
void dfs1(const int &u) {
	sz[u]=1; int v;
	for(int i=ihead[u]; i; i=inext[i]) if(fa[u]!=(v=to[i])) {
		fa[v]=u;
		dep[v]=dep[u]+1;
		dfs1(v);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]) son[u]=v;
	}
}
void dfs2(const int &u, const int &tp) {
	id[u]=++tot; top[u]=tp; b[tot]=a[u];
	if(son[u]) dfs2(son[u], tp);
	for(int i=ihead[u]; i; i=inext[i]) if(to[i]!=fa[u] && to[i]!=son[u]) dfs2(to[i], to[i]);
}
void build(const int &l, const int &r, const int &x) {
	if(l==r) { t[x].mx=t[x].sum=b[l]; return; }
	int m=MID;
	build(lson); build(rson);
	pushup(x); 
}
void update(const int &l, const int &r, const int &x) {
	if(l==r) { t[x].mx=t[x].sum=key; return; }
	int m=MID;
	if(L<=m) update(lson);
	if(m<R) update(rson);
	pushup(x); 
}
int getmax(const int &l, const int &r, const int &x) {
	if(L<=l && r<=R) return t[x].mx;
	int m=MID, mx=oo+1;
	if(L<=m) mx=max(mx, getmax(lson));
	if(m<R) mx=max(mx, getmax(rson));
	return mx;
}
int query(const int &l, const int &r, const int &x) {
	if(L<=l && r<=R) return t[x].sum;
	int m=MID, ret=0;
	if(L<=m) ret+=query(lson);
	if(m<R) ret+=query(rson);
	return ret;
}
inline int getmax(int x, int y) {
	int fx=top[x], fy=top[y], ret=oo+1;
	while(fx!=fy) {
		if(dep[fx]<dep[fy]) { swap(x, y); swap(fx, fy); }
		L=id[fx], R=id[x];
		ret=max(ret, getmax(1, n, 1));
		x=fa[fx]; fx=top[x];
	}
	if(dep[x]>dep[y]) swap(x, y);
	L=id[x], R=id[y];
	return max(ret, getmax(1, n, 1));
}
inline int query(int x, int y) {
	int fx=top[x], fy=top[y], ret=0;
	while(fx!=fy) {
		if(dep[fx]<dep[fy]) { swap(x, y); swap(fx, fy); }
		L=id[fx], R=id[x];
		ret+=query(1, n, 1);
		x=fa[fx]; fx=top[x];
	}
	if(dep[x]>dep[y]) swap(x, y);
	L=id[x], R=id[y];
	return ret+query(1, n, 1);
}
inline void add(const int &u, const int &v) {
	inext[++cnt]=ihead[u]; ihead[u]=cnt; to[cnt]=v;
	inext[++cnt]=ihead[v]; ihead[v]=cnt; to[cnt]=u;
}
int main() {
	read(n);
	int u, v, ans;
	for(int i=1; i<n; ++i) {
		read(u); read(v);
		add(u, v);
	}
	for(int i=1; i<=n; ++i) read(a[i]);
	dfs1(1);
	dfs2(1, 1);
	build(1, n, 1);
	char c[10];
	read(m);
	for(int i=0; i<m; ++i) {
		scanf("%s", c);
		if(c[0]=='C') {
			read(u); read(key); L=R=id[u];
			update(1, n, 1);
		}
		else if(c[0]=='Q') {
			read(u); read(v);
			if(c[1]=='M') ans=getmax(u, v);
			else ans=query(u, v);
			printf("%d\n", ans);
		}
	}
	return 0;
}
