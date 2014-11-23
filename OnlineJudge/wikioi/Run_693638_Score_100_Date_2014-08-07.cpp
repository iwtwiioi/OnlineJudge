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
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define read(a) a=getnum()
#define print(a) printf("%d", a)
#define num(i, j) ((i-1)*n+j)
#define who(i, j) (!((i+j)%2))
#define arr(a, n) for1(i, 1, n) { for1(j, 1, n) print(a[i][j]); printf("\n"); }
#define arr2(a, n) for1(i, 1, n) print(a[i]); printf("\n")
inline int getnum() { int ret=0; char c; int k=1; for(c=getchar(); c<'0' || c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0' && c<='9'; c=getchar()) ret=ret*10+c-'0'; return k*ret; }

const int fx[8]={1, 1, 2, 2, -1, -1, -2, -2}, fy[8]={2, -2, 1, -1, 2, -2, 1, -1};
const int N=205*205, M=500001, oo=~0u>>1;
int ihead[N], cnt=1, n, m;
int gap[N], p[N], d[N], cur[N];
bool mm[205][205];
struct dd { int to, from, cap, next; }e[M];

inline void add(const int &u, const int &v, const int &c) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].from=u; e[cnt].to=v; e[cnt].cap=c;
	e[++cnt].next=ihead[v]; ihead[v]=cnt; e[cnt].from=v; e[cnt].to=u; e[cnt].cap=0;
}

int isap(const int &s, const int &t, const int &n) {
	int flow=0, u=s, f, i, v;
	for1(i, 0, n) cur[i]=ihead[i];
	gap[0]=n;
	while(d[s]<n) {
		for(i=cur[u]; i; i=e[i].next) if(e[i].cap && d[u]==d[v=e[i].to]+1) break;
		if(i) {
			cur[u]=i; p[v]=i; u=v;
			if(u==t) {
				for(f=oo; u!=s; u=e[p[u]].from) f=min(f, e[p[u]].cap);
				for(u=t; u!=s; u=e[p[u]].from) e[p[u]].cap-=f, e[p[u]^1].cap+=f;
				flow+=f;
			}
		}
		else {
			if(!(--gap[d[u]])) break;
			d[u]=n;
			cur[u]=ihead[u];
			for(i=cur[u]; i; i=e[i].next) if(e[i].cap && d[u]>d[e[i].to]+1)
				d[u]=d[e[i].to]+1;
			++gap[d[u]]; if(u!=s) u=e[p[u]].from;
		}
	}
	return flow;
}

int main() {
	read(n); read(m);
	int a, b, nx, ny, s=0, t=n*n+5;
	rep(i, m) read(a), read(b), mm[a][b]=1;
	for1(i, 1, n) for1(j, 1, n) if(!mm[i][j]) {
		if(who(i, j)) {
			rep(k, 8) {
				nx=i+fx[k], ny=j+fy[k];
				if(mm[nx][ny] || nx<1 || nx>n || ny<1 || ny>n) continue;
				add(num(i, j), num(nx, ny), oo);
			}
			add(s, num(i, j), 1);
		}
		else add(num(i, j), t, 1);
	}
	print(n*n-isap(s, t, t+1)-m);
	
	return 0;
}
