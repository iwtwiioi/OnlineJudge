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
#define who(i, j) (i%2==j%2)
#define arr(a, n) for1(i, 1, n) { for1(j, 1, n) print(a[i][j]); printf("\n"); }
#define arr2(a, n) for1(i, 1, n) print(a[i]); printf("\n")
inline int getnum() { int ret=0; char c; int k=1; for(c=getchar(); c<'0' || c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0' && c<='9'; c=getchar()) ret=ret*10+c-'0'; return k*ret; }

const int fx[8]={1, 1, 2, 2, -1, -1, -2, -2}, fy[8]={-2, 2, -1, 1, -2, 2, -1, 1};
const int N=205*205, M=N*16+100, oo=~0u>>1;
int ihead[N], inext[M], from[N], to[M], cap[M], cnt=1, n, m;
int gap[N], p[N], d[N], cur[N];
bool mm[205][205];

inline void add(const int &u, const int &v, const int &c) {
	inext[++cnt]=ihead[u]; ihead[u]=cnt; from[cnt]=u; to[cnt]=v; cap[cnt]=c;
	inext[++cnt]=ihead[v]; ihead[v]=cnt; from[cnt]=v; to[cnt]=u; cap[cnt]=0;
}

int isap(const int &s, const int &t, const int &n) {
	int flow=0, u=s, f, i;
	for1(i, 0, n) cur[i]=ihead[i];
	gap[0]=n;
	while(d[s]<n) {
		for(i=cur[u]; i; i=inext[i]) if(cap[i] && d[u]==d[to[i]]+1) break;
		if(i) {
			cur[u]=i; p[to[i]]=i; u=to[i];
			if(u==t) {
				for(f=oo; u!=s; u=from[p[u]]) f=min(f, cap[p[u]]);
				for(u=t; u!=s; u=from[p[u]]) cap[p[u]]-=f, cap[p[u]^1]+=f;
				flow+=f;
			}
		}
		else {
			if(!(--gap[d[u]])) break;
			d[u]=n;
			cur[u]=ihead[u];
			for(i=ihead[u]; i; i=inext[i]) if(cap[i] && d[u]>d[to[i]]+1)
				d[u]=d[to[i]]+1;
			++gap[d[u]]; if(u!=s) u=from[p[u]];
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
