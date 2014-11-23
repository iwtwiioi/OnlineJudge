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
#define dbg(x) cout << (#x) << " = " << (x) << endl
#define printarr2(a, b, c) for1(_, 1, b) { for1(__, 1, c) cout << a[_][__]; cout << endl; }
#define printarr1(a, b) for1(_, 1, b) cout << a[_] << '\t'; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=2005;
int ihead[N], cnt, rt, iscut[N], FF[N], LL[N], fa[N], tot;
struct ED { int to, next; }e[N*N];
void add(int u, int v) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v;
	e[++cnt].next=ihead[v]; ihead[v]=cnt; e[cnt].to=u;
}
void tarjan(int u, int fa) {
	FF[u]=LL[u]=++tot;
	int child=0;
	for(int i=ihead[u]; i; i=e[i].next) {
		int v=e[i].to;
		if(!FF[v]) {
			tarjan(v, u);
			++child;
			if(LL[v]>=FF[u]) ++iscut[u]; //dbg(iscut[u]); dbg(u);
			LL[u]=min(LL[v], LL[u]);
		}
		else if(FF[v]<FF[u] && fa!=v) LL[u]=min(LL[u], FF[v]);
	}
	if(child==1 && fa==-1) iscut[u]=0;
	else if(child>1 && fa==-1) iscut[u]=child-1;
}

int main() {
	int u, v, cs=0;
	while(1) {
		u=getint(); if(u==0) break;
		v=getint();
		CC(ihead, 0); CC(iscut, 0); cnt=tot=0; CC(FF, 0); CC(LL, 0);
		++cs;
		add(u, v); rt=max(rt, v);
		while(1) {
			u=getint(); if(u==0) break;
			v=getint();
			add(u, v); rt=max(rt, v);
		}
		for1(i, 1, rt) if(ihead[i] && !FF[i]) tarjan(i, -1);
		// for1(i, 1, rt) if(hav[i] && iscut[i]) printf("%d\n", i);
		int flag=0;
		printf("Network #%d\n", cs);
		for1(i, 1, rt) if(iscut[i]) printf("  SPF node %d leaves %d subnets\n", i, iscut[i]+1), flag=1;
		if(!flag) puts("  No SPF nodes");
		puts("");
	}
	return 0;
}