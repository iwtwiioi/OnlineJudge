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

const int oo=1000000000, N=1005, M=100005;
int h[N], ihead1[N], ihead2[N], cnt1, cnt2, vis[N], n, m;
struct astr {
	int v, g, f;
	const bool operator< (const astr &b) const {
		return f==b.f?(g>b.g):(f>b.f);
	}
};
struct ED { int v, next, w; }e1[M], e2[M];
priority_queue<astr> pq;
queue<int> q;
inline void add(const int &u, const int &v, const int &w) {
	e1[++cnt1].next=ihead1[u]; ihead1[u]=cnt1; e1[cnt1].v=v; e1[cnt1].w=w;
	e2[++cnt2].next=ihead2[v]; ihead2[v]=cnt2; e2[cnt2].v=u; e2[cnt2].w=w;
}
void spfa(const int &s) {
	int u;
	for1(i, 1, n) h[i]=oo;
	CC(vis, 0);
	h[s]=0; vis[s]=1; q.push(s);
	while(!q.empty()) {
		u=q.front(); q.pop(); vis[u]=0;
		for(int i=ihead2[u]; i; i=e2[i].next) if(h[u]+e2[i].w<h[e2[i].v]) {
			h[e2[i].v]=h[u]+e2[i].w;
			if(!vis[e2[i].v]) { vis[e2[i].v]=1; q.push(e2[i].v); }
		}
	}
}
int getans(const int &s, const int &t, int k) {
	if(h[s]==oo) return -1;
	if(s==t) ++k;
	while(!pq.empty()) pq.pop();
	int num=0;
	astr now, tp; now.v=s; now.g=0; now.f=now.g+h[now.v];
	pq.push(now);
	while(!pq.empty()) {
		now=pq.top(); pq.pop();
		if(now.v==t) ++num;
		if(num==k) return now.g;
		for(int i=ihead1[now.v]; i; i=e1[i].next) {
			tp.v=e1[i].v; 
			tp.g=now.g+e1[i].w; 
			tp.f=tp.g+h[tp.v];
			pq.push(tp);
		}
	}
	return -1;
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		int u, v, w;
		cnt1=cnt2=0; CC(ihead1, 0); CC(ihead2, 0);
		rep(i, m) {
			read(u); read(v); read(w);
			add(u, v, w);
		}
		read(u); read(v); read(w);
		spfa(v);
		printf("%d\n", getans(u, v, w));
	}
	return 0;
}

