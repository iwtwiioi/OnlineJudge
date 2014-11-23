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
inline int getnum() { int ret=0; char c; for(c=getchar(); c<'0' || c>'9'; c=getchar()); for(; c>='0' && c<='9'; c=getchar()) ret=ret*10+c-'0'; return ret; }

const int N=40005, M=N*4*2, oo=~0u>>2;
int ihead[N], inext[M], from[M], to[M], cap[M], cnt=1;
int gap[N], d[N], cur[N], p[N];

inline void add(const int &u, const int &v, const int &w) {
	inext[++cnt]=ihead[u]; ihead[u]=cnt; from[cnt]=u; to[cnt]=v; cap[cnt]=w;
	inext[++cnt]=ihead[v]; ihead[v]=cnt; from[cnt]=v; to[cnt]=u; cap[cnt]=0;
}

inline int isap(const int &s, const int &t, const int &n) {
	int u=s, f, i, flow=0;
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
			++gap[d[u]];
			if(u!=s) u=from[p[u]];
		}
	}
	return flow;
}

int main() {
	int t, u, n;
	read(n);
	int S=0, T=n*n+1;
	int sum=0, last;
	for1(i, 1, n) {
		last=i;
		for1(j, 1, n) {
			read(t); sum+=t;
			u=(i-1)*n+j;
			if(last%2) {
				if(i>1) add(u, u-n, oo);
				if(i<n) add(u, u+n, oo);
				if(j>1) add(u, u-1, oo);
				if(j<n) add(u, u+1, oo);
				add(S, u, t);
			}
			else add(u, T, t);
			++last;
		}
	}
	printf("%d\n", sum-isap(S, T, T+1));
	
	return 0;
}

