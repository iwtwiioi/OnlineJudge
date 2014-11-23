#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define for1(i,a,n) for(i=a;i<=n;++i)
#define for2(i,a,n) for(i=a;i<n;++i)
#define for3(i,a,n) for(i=a;i>=n;--i)
#define for4(i,a,n) for(i=a;i>n;--i)
#define CC(i,a) memset(i,a,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define read(a) a=getnum()
#define print(a) printf("%d", a)
inline int getnum() { int ret=0; char c; for(c=getchar(); c<'0' || c>'9'; c=getchar()); for(; c>='0' && c<='9'; c=getchar()) ret=ret*10+c-'0'; return ret; }

const int N=300, M=N*N;
int ihead[N], inext[M], from[M], to[M], cnt, ans;
int x[N], y[N+N];
bool visy[N+N];
inline void add(int u, int v) {
	inext[++cnt]=ihead[u]; ihead[u]=cnt; from[cnt]=u; to[cnt]=v;
	inext[++cnt]=ihead[v]; ihead[v]=cnt; from[cnt]=v; to[cnt]=u;
}

bool ifind(int u) {
	int v, i;
	for(i=ihead[u]; i; i=inext[i]) if(!visy[v=to[i]]) {
		visy[v]=true;
		if(!y[v] || ifind(y[v])) {
			y[v]=u;
			return true;
		}
	}
	return false;
}

int main() {
	int t; read(t);
	int n, i, j, k;
	while(t--) {
		read(n);
		ans=1;
		CC(y, 0);
		CC(ihead, 0);
		for1(i, 1, n) for1(j, 1, n) {
			read(k);
			if(k) add(i, n+j);
		}
		for1(i, 1, n) {
			CC(visy, 0);
			if(!ifind(i)) { ans=0; break; }
		}
		if(ans) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

