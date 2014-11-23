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

const int N=10006, M=5*N, oo=~0u>>2;
int n, ihead[N], d[3][N], m, q[N], front, tail, vis[N], cnt, tot, P[M], Q[M], U[M], V[M];
struct ED { int to, w, next; }e[M];
void add(int u, int v) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v;
}

void spfa(int s, int *d) {
	for1(i, 1, n) d[i]=oo;
	front=tail=0;
	vis[s]=1; q[tail++]=s; d[s]=0;
	int v;
	while(front!=tail) {
		int u=q[front++]; if(front==N) front=0; vis[u]=0;
		for(int i=ihead[u]; i; i=e[i].next) if(d[v=e[i].to]>d[u]+e[i].w) {
			d[v]=d[u]+e[i].w;
			if(!vis[v]) {
				vis[v]=1;
				q[tail++]=v; if(tail==N) tail=0;
			}
		}
	}
}

int main() {
	read(n); read(m);
	for1(i, 1, m) {
		int u=getint(), v=getint();
		add(v, u);
		P[i]=getint(); Q[i]=getint();
		U[i]=u; V[i]=v;
	}
	for1(i, 1, cnt) e[i].w=P[i];
	spfa(n, d[0]);
	for1(i, 1, cnt) e[i].w=Q[i];
	spfa(n, d[1]);
	CC(ihead, 0); cnt=0;
	for1(i, 1, m) {
		int u=U[i], v=V[i];
		add(u, v);
		e[i].w=2;
		if(d[0][u]==d[0][v]+P[i]) --e[i].w;
		if(d[1][u]==d[1][v]+Q[i]) --e[i].w;
	}
	spfa(1, d[2]);
	if(d[2][n]==oo) d[2][n]=-1;
	print(d[2][n]);
	return 0;
}

