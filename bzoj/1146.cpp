#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define dbg(x) cout << #x << "=" << x << endl
#define read(x) x=getint()
#define rdm(u) for(int i=ihead[u]; i; i=e[i].next)
#define lc x<<1
#define rc x<<1|1
#define lson l, m, lc
#define rson m+1, r, rc
#define MID (l+r)>>1
inline const int getint() { char c=getchar(); int ret=0, k=1; for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) ret=ret*10+c-'0'; return k*ret; }
const int N=80010, oo=~0u>>1;
int n, q, ihead[N], brr[N], arr[N], cnt, bak, flg, L, R, same;
int fa[N], top[N], son[N], dep[N], sz[N], id[N], tot, num;
struct Ed { int to, next; }e[N<<1];
inline void add(const int &u, const int &v) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v;
	e[++cnt].next=ihead[v]; ihead[v]=cnt; e[cnt].to=u;
}

struct node* null;
struct node { 
	node* ch[2]; int wei, key, sz, cnt;
	void pushup() { sz=ch[0]->sz+ch[1]->sz+cnt; }
	node(int _w=0, int _sz=1, int _cnt=1) : key(_w), sz(_sz), cnt(_cnt) {
		ch[0]=ch[1]=null; wei=rand();
	}
}*root[N*50], *nd[N*50];
inline void rot(node* &x, const bool d) {
	node* t=x->ch[!d]; x->ch[!d]=t->ch[d]; t->ch[d]=x;
	x->pushup(); t->pushup();
	x=t;
}
void insert(node* &x, const int &key) {
	if(x==null) { x=new node(key); return; }
	if(key==x->key) { ++x->cnt; ++x->sz; return; }
	bool d=key>x->key;
	insert(x->ch[d], key);
	if(x->wei>x->ch[d]->wei) rot(x, !d);
	x->pushup();
}
void remove(node* &x, const int &key) {
	if(x==null) return;
	bool d=key>x->key;
	if(key==x->key) {
		if(x->cnt>1) { --x->cnt; --x->sz; return; }
		d=x->ch[0]->wei > x->ch[1]->wei;
		if(x->ch[d]==null) {
			delete x;
			x=null;
			return;
		}
		rot(x, !d);
		remove(x->ch[!d], key);
	}
	else remove(x->ch[d], key);
	x->pushup();
}
inline int rank(node* x, const int &key) {
	int ret=0, s;
	while(x!=null) {
		s=x->ch[1]->sz + x->cnt;
		if(key==x->key) same+=x->cnt; 
		if(key<x->key) ret+=s, x=x->ch[0];
		else x=x->ch[1];
	}
	return ret;
}
void build(const int &l, const int &r, const int &x) {
	if(l==r) { root[x]=new node(brr[l]); return; }
	int m=MID;
	build(lson); build(rson);
	root[x]=new node(brr[l]);
	for(int i=l+1; i<=r; ++i) insert(root[x], brr[i]);
}
void update(const int &l, const int &r, const int &x) {
	if(l==r) { 
		remove(root[x], bak);
		insert(root[x], flg);
		return;
	}
	int m=MID;
	remove(root[x], bak);
	insert(root[x], flg);
	if(L<=m) update(lson); if(m<R) update(rson);
}
void query(const int &l, const int &r, const int &x) {
	if(L<=l && r<=R) { nd[++num]=root[x]; return; }
	int m=MID;
	if(L<=m) query(lson);
	if(m<R) query(rson);
}
void dfs1(const int &u) {
	sz[u]=1; int v;
	rdm(u) if(fa[u]!=(v=e[i].to)) {
		fa[v]=u; dep[v]=dep[u]+1;
		dfs1(v);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]) son[u]=v;
	}
}
void dfs2(const int &u, const int &tp) {
	id[u]=++tot; top[u]=tp; brr[tot]=arr[u];
	if(son[u]) dfs2(son[u], tp);
	rdm(u) if(fa[u]!=e[i].to && son[u]!=e[i].to) dfs2(e[i].to, e[i].to);
}
void getrange(int x, int y) {
	num=0;
	int fx=top[x], fy=top[y];
	while(fx!=fy) {
		if(dep[fx]<dep[fy]) { swap(x, y); swap(fx, fy); }
		L=id[fx], R=id[x];
		query(1, n, 1);
		x=fa[fx]; fx=top[x];
	}
	if(dep[x]>dep[y]) swap(x, y);
	L=id[x], R=id[y];
	query(1, n, 1);
}
int getrank(const int &key) {
	int ret=0; same=0;
	for(int i=1; i<=num; ++i) ret+=rank(nd[i], key);
	return ret;
}
int getans(int x, int y, int k) {
	getrange(x, y);
	node* rt; int l=oo+1, r=oo, s=0;
	for(int i=1; i<=num; ++i) s+=nd[i]->sz;
	if(s<k) return l;
	for(int i=1; i<=num; ++i) {
		rt=nd[i];
		while(rt!=null) {
			if(rt->key<l) { rt=rt->ch[1]; continue; }
			if(rt->key>r) { rt=rt->ch[0]; continue; }
			s=getrank(rt->key);
			if(s+1<=k && k<=s+same)  return rt->key; 
			if(s+same>k) { l=rt->key; rt=rt->ch[1]; }
			else { r=rt->key; rt=rt->ch[0]; }
		}
	}
	return l;
}
int main() {
	null=new node(0, 0, 0); null->wei=oo;
	read(n); read(q);
	int u, v, k, ans;
	for(int i=1; i<=n; ++i) read(arr[i]);
	for(int i=1; i<n; ++i) { read(u); read(v); add(u, v); }
	dfs1(1); dfs2(1, 1); build(1, n, 1);
	while(q--) {
		read(k); read(u); read(v);
		if(!k) {
			bak=arr[u]; flg=arr[u]=v;
			L=R=id[u];
			update(1, n, 1);
		}
		else {
			ans=getans(u, v, k);
			if(ans==oo+1) puts("invalid request!");
			else printf("%d\n", ans);
		}
	}
	return 0;
}
