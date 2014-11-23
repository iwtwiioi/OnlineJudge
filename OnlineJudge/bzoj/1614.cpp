#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <string>
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

using namespace std;

const int N=1005;
int d[N], ihead[N], cnt, vis[N], q[N], tail, front, n, m, k;
struct ED { int to, next, w; } e[N*N];
inline void add(const int &u, const int &v, const int &w) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v; e[cnt].w=w;
}
inline const bool spfa(const int &x) {
	CC(d, 0x3f);
	d[1]=tail=front=0; vis[1]=1; q[tail++]=1;
	int u, v, t;
	while(front!=tail) {
		u=q[front++]; if(front==N) front=0; vis[u]=0;
		for(int i=ihead[u]; i; i=e[i].next) {
			v=e[i].to;
			if(e[i].w>x) t=d[u]+1;
			else t=d[u];
			if(t<d[v]) {
				d[v]=t;
				if(!vis[v]) { vis[v]=1; q[tail++]=v; if(tail==N) tail=0; }
			}
		}
	}
	return d[n]<=k;
}

int main() {
	read(n); read(m); read(k);
	int u, v, w;
	while(m--) {
		read(u); read(v); read(w);
		add(u, v, w); add(v, u, w);
	}
	int l=0, r=1000000, mid;
	while(l<=r) {
		mid=(l+r)>>1;
		if(spfa(mid)) r=mid-1;
		else l=mid+1;
	}
	if(l>1000000) puts("-1");
	else print(r+1);
	return 0;
}
