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
#define debug(x) printf("debug: %d\n", x)
#define printarr(a, x) { for1(i, 0, x) printf("%d ", a[i]); printf("\n"); }
inline int getnum() { int ret=0; char c; int k=1; for(c=getchar(); c<'0' || c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0' && c<='9'; c=getchar()) ret=ret*10+c-'0'; return ret*k; }

const int N=305;
int ihead[N], inext[N*N>>1], to[N*N>>1], cnt, sum[N], n, m;
bool vis[N], die[N], vis2[N];

inline void pushup(int x) { sum[x]=1; for(int i=ihead[x]; i; i=inext[i]) sum[x]+=sum[to[i]]; }
inline void add(int u, int v) {
	inext[++cnt]=ihead[u]; ihead[u]=cnt; to[cnt]=v;
}

void build(const int &x) {
	for(int i=ihead[x]; i; i=inext[i]) build(to[i]);
	pushup(x);
}

int main() {
	read(n); read(m);
	int a, b;
	rep(i, m) { read(a); read(b); add(a, b); }
	vis[1]=die[1]=true;
	bool flag;
	int maxi, v, ans=0;
	build(1);
	int fff=sum[1];
	for1(ttt, 1, fff) {
		flag=1; maxi=0;
		memcpy(vis2, vis, sizeof(vis));
		for1(u, 1, n) if(vis2[u]) {
			for(int i=ihead[u]; i; i=inext[i]) {
				v=to[i];
				die[v]=1;
				flag=0;
				if(sum[v]>sum[maxi]) maxi=v;
				vis[v]=true;
			}
			vis[u]=vis[maxi]=die[maxi]=false;
		}
		if(flag) break;
	}
	for1(i, 1, n) if(die[i]) ans++;
	print(ans);
	return 0;
}
