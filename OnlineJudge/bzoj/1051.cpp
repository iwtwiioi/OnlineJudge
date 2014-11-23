#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
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

const int N=10005, M=50005;
int ihead[N], inext[M], to[M], cnt;
int LL[N], FF[N], top, s[N], p[N], cyc, tot, vis[N], hav[N];
int p_ihead[N], p_inext[M], p_cnt;
int n, m, ans;

inline void add(const int &u, const int &v) {
	inext[++cnt]=ihead[u]; ihead[u]=cnt; to[cnt]=v;
}

void dfs(int u) {
	s[++top]=u;
	vis[u]=1;
	LL[u]=FF[u]=++tot;
	for(int i=ihead[u]; i; i=inext[i]) {
		if(!FF[to[i]]) {
			dfs(to[i]);
			LL[u]=min(LL[u], LL[to[i]]);
		}
		else if(vis[to[i]] && FF[to[i]]<LL[u])
			LL[u]=FF[to[i]];
	}
	if(LL[u]==FF[u]) {
		++cyc;
		int r;
		do {
			r=s[top--];
			p[r]=cyc;
			vis[r]=0;
			++hav[cyc];
		} while(r!=u);
	}
}

void rebuild() {
	for1(u, 1, n) {
		for(int i=ihead[u]; i; i=inext[i]) {
			if(p[u] != p[to[i]]) {
				p_inext[++p_cnt]=p_ihead[p[u]];
				p_ihead[p[u]]=p_cnt;
			}
		}
	}
}

void tarjan() {
	for1(i, 1, n) if(!FF[i]) dfs(i);
	rebuild();
}

void getans() {
	for1(i, 1, cyc) if(!p_ihead[i]) {
		if(ans) { ans=0; return; }
		else ans=hav[i];
	}
}

int main() {
	int x, y;
	read(n); read(m);
	for1(i, 0, n+1) p[i]=i;
	rep(i, m) {
		read(x); read(y);
		add(x, y);
	}
	tarjan();
	getans();
	print(ans);
	return 0;
}

