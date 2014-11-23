#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define dbg(x) cout << #x << " = " << x << endl
#define rep(i, n) for(int i=0; i<n; ++i)
#define for1(i, a, n) for(int i=a; i<=(n); ++i)
#define read(x) x=getint()
#define MID (l+r)>>1
#define rdm(u) for(int i=ihead[u]; i; i=e[i].next)
using namespace std;
inline const int getint() { char c=getchar(); int k=1, r=0; for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
const int N=80005;
struct ED { int to, next; } e[N<<1];
struct ND { int l, r, s; } t[N*80];
int ihead[N], root[N], c[N], cnt, tot, num, suml, sumr, n, m, lca[N], L[N<<2], R[N<<2], FF[N], LL[N], fa[N], p[N], a[N], ans[N+N], u[N], v[N], K[N];
bool vis[N];
vector<pair<int, int> > q[N];
inline void add(const int &u, const int &v) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v;
	e[++cnt].next=ihead[v]; ihead[v]=cnt; e[cnt].to=u;
}
void update(const int &l, const int &r, int &pos, const int &key, const int &sz) {
	t[++tot]=t[pos]; pos=tot; t[pos].s+=sz;
	if(l==r) return;
	int m=MID;
	if(key<=m) update(l, m, t[pos].l, key, sz); else update(m+1, r, t[pos].r, key, sz);
}
int query(const int &l, const int &r, const int &k) {
	if(l==r) return l;
	int s=0, tt=0, m=MID;
	for1(i, 1, sumr) s+=t[t[R[i]].r].s, tt+=t[R[i]].s; //将池子里要加减的求和
	for1(i, 1, suml) s-=t[t[L[i]].r].s, tt-=t[L[i]].s;
	if(tt<k) return -1; //当数目不够时，自己可以算算
	if(k<=s) { //这里是求k大，不是k小！！！
		for1(i, 1, suml) L[i]=t[L[i]].r;
		for1(i, 1, sumr) R[i]=t[R[i]].r;
		return query(m+1, r, k);
	}
	else {
		for1(i, 1, suml) L[i]=t[L[i]].l;
		for1(i, 1, sumr) R[i]=t[R[i]].l;
		return query(l, m, k-s);
	}
}
inline void get(int x, const int &k) {
	if(k) { R[++sumr]=root[x]; for(x=FF[x]; x; x-=(x&-x)) R[++sumr]=c[x]; } //这里要注意，要加上原本信息，即root
	else  { L[++suml]=root[x]; for(x=FF[x]; x; x-=(x&-x)) L[++suml]=c[x]; }
}
inline void change(int x, const int &key, const int& k) {
	for(; x<=n; x+=(x&-x)) update(1, num, c[x], key, k);
}
int ifind(const int &x) { return x==p[x]?x:p[x]=ifind(p[x]); }
void dfs(const int &x) {
	p[x]=x; root[x]=root[fa[x]]; update(1, num, root[x], a[x], 1);
	static int nm=0;
	FF[x]=++nm; //首次发现x的序
	rdm(x) if(fa[x]!=e[i].to) { fa[e[i].to]=x; dfs(e[i].to); p[e[i].to]=x; }
	LL[x]=nm; //遍历完x的所有子树后的序，那么这些子树的连续区间就是[FF[x], LL[x]]
	vis[x]=1;
	int t=q[x].size();
	rep(i, t) if(vis[q[x][i].first]) lca[q[x][i].second]=ifind(q[x][i].first);
}

int main() {
	read(n); read(m); int tt=0;
	for1(i, 1, n) { read(a[i]); ans[++tt]=a[i]; }
	rep(i, n-1) add(getint(), getint());
	for1(i, 1, m) {
		read(K[i]); read(u[i]); read(v[i]);
		if(K[i]) {
			q[u[i]].push_back(pair<int, int> (v[i], i));
			q[v[i]].push_back(pair<int, int> (u[i], i));
		}
		else ans[++tt]=v[i];
	}
	sort(ans+1, ans+1+tt); ans[tt+1]=1000000013; //离散
	for1(i, 1, tt) if(ans[i]!=ans[i+1]) ans[++num]=ans[i]; //将重叠的合并，缩短主席树的区间范围
	for1(i, 1, n) a[i]=lower_bound(ans+1, ans+1+num, a[i])-ans; //查找原来元素在ans域的位置，即主席树上对应的区间值
	dfs((n+1)>>1); //这里我们从中间遍历，防止爆栈（至于为什么，你自己画一条长链，你懂的）
	int out, x, y;
	for1(i, 1, m) {
		if(K[i]) {
			suml=sumr=0;
			get(u[i], 1); get(v[i], 1); //将u到根、v到根的原本信息（root）和修改信息（c）全部放到池子里
			get(lca[i], 0); get(fa[lca[i]], 0); //同上
			out=query(1, num, K[i]);
			if(out<=0) puts("invalid request!");
			else printf("%d\n", ans[out]);
		}
		else {
			x=u[i]; y=v[i];
			y=lower_bound(ans+1, ans+1+num, y)-ans; //求出修改的值在ans的位置
			change(FF[x], a[x], -1); change(LL[x]+1, a[x], 1); //首先将区间[FF[x], n]全部减去a[x]，然后将区间[LL[x]+1, n]全部加回a[x]
			change(FF[x], y, 1); change(LL[x]+1, y, -1); //同上
			a[x]=y;
		}
	}
	return 0;
}
