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
inline int getnum() { int ret=0; char c; int k=1; for(c=getchar(); c<'0' || c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0' && c<='9'; c=getchar()) ret=ret*10+c-'0'; return k*ret; }

const int N=1005;
int x[N], y[N];
struct edge {
	int u, v, w;
	bool operator < (const edge &a) const { return w<a.w; }
}e[N*N];
int cnt;
int f[N];
int ifind(const int &x) { return x==f[x]?x:f[x]=ifind(f[x]); }

int main() {
	int n, m;
	read(n); read(m);
	for1(i, 1, n) read(x[i]), read(y[i]);
	for1(i, 1, n) f[i]=i;
	for1(i, 1, n) for1(j, 1, n) if(i!=j) e[cnt].u=i, e[cnt].v=j, e[cnt++].w=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
	sort(e, e+cnt);
	int fu, fv;
	for2(i, 0, cnt) {
		fu=ifind(e[i].u); fv=ifind(e[i].v);
		if(fu!=fv) {
			if(n>m) --n, f[fu]=fv;
			else {
				printf("%.2lf\n", sqrt(e[i].w));
				break;
			}
		}
	}
	return 0;
}

