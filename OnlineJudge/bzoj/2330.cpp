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
int ihead[N], n, m, vis[N], tm[N], cnt, q[N], front, tail;
long long d[N];
struct ED { int to, next, w; } e[3000000];
inline void add(const int &u, const int &v, const int &w) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v; e[cnt].w=w;
}
const bool spfa() {
	for1(i, 1, n) q[i]=i, d[i]=1, vis[i]=1, tm[i]=1;
	front=1; tail=n+1;
	int u, v;
	while(front!=tail) {
		u=q[front++]; if(front==N) front=0; vis[u]=0;
		for(int i=ihead[u]; i; i=e[i].next) if(d[v=e[i].to]<d[u]+e[i].w) {
			d[v]=d[u]+e[i].w;
			if(++tm[v]>=n) return 0; //环的点数>=n，每个点最多更新n-1次。
			if(!vis[v]) {
				vis[v]=1; q[tail++]=v;
				if(tail==N) tail=0;
			}
		}
	}
	return 1;
}

int main() {
	read(n); read(m);
	int u, v, x;
	for1(i, 1, m) {
		read(x); read(u); read(v);
		if(x==1) add(u, v, 0), add(v, u, 0);
		else if(x==2) { 
			if(u==v) { puts("-1"); return 0; }
			add(u, v, 1);
		}
		else if(x==3) add(v, u, 0);
		else if(x==4) {
			if(u==v) { puts("-1"); return 0; }
			add(v, u, 1);
		}
		else add(u, v, 0);
	}
	if(spfa()) {
		long long ans=0;
		for1(i, 1, n) ans+=d[i];
		printf("%lld", ans);
	}
	else puts("-1");
	return 0;
}

