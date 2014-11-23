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
inline int getnum() { int ret=0; char c; int k=1; for(c=getchar(); c<'0' || c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0' && c<='9'; c=getchar()) ret=ret*10+c-'0'; return k*ret; }

struct edge {
	int u, v, w;
	bool operator < (const edge &a) const { return w<a.w; }
}e[10005];

int cnt, f[2005];
int ifind(const int &x) { return x==f[x]?x:f[x]=ifind(f[x]); }
int main() {
	int n, m;
	read(n); read(m);
	for1(i, 1, n) f[i]=i;
	int u, v, w, fu, fv, p, ans=0;
	for1(i, 1, m) {
		read(p); read(u); read(v); read(w);
		if(p==1) {
			ans+=w;
			f[ifind(u)]=ifind(v);
		}
		else e[cnt].u=u, e[cnt].v=v, e[cnt++].w=w;
	}
	sort(e, e+cnt);
	for1(i, 0, cnt) {
		fu=ifind(e[i].u); fv=ifind(e[i].v);
		if(fu!=fv) {
			f[fu]=fv;
			ans+=e[i].w;
		}
	}
	print(ans);
	return 0;
}

