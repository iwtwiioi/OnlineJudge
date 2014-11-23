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
#define read(a) a=getint()
#define print(a) printf("%d", a)
#define dbg(x) cout << #x << " = " << x << endl
#define printarr(a, n, m) rep(aaa, n+1) { rep(bbb, m+1) cout << a[aaa][bbb]; cout << endl; }
inline int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }
const int N=310, M=5010, T=60, oo=20000000;
bool ck[T][N][N];
int p[N], n, m, t, v, k, d[T][T], f[T];
struct ED { int x, y, w; }e[M];
const int ifind(const int &x) { return x==p[x]?x:p[x]=ifind(p[x]); }
const bool check(const int &x, const int &y, const int &u, const int &v) { for1(i, x, y) if(ck[i][u][v]) return false; return true;}
const bool cmp(const ED &a, const ED &b) { return a.w<b.w; }
inline int getans(const int &x, const int &y) {
	for1(i, 1, n) p[i]=i;
	int fx, fy, ret=0;
	for1(i, 1, m) {
		fx=ifind(e[i].x); fy=ifind(e[i].y);
		if(fx!=fy && check(x, y, e[i].x, e[i].y)) {
			p[fx]=fy;
			ret+=e[i].w;
		}
	}
	for1(i, 1, n) if(ifind(i)!=ifind(1)) return oo;
	return ret;
}

int main() {
	scanf("%d%d%d%d%d", &n, &m, &t, &v, &k);
	int x, y, c, l, r;
	for1(i, 1, m) { read(x); read(y); read(c); if(x>y) swap(x, y);  e[i].x=x; e[i].y=y; e[i].w=c; }
	sort(e+1, e+1+m, cmp);
	int p=getint();
	while(p--) {
		read(x); read(y); read(l); read(r);
		if(x>y) swap(x, y); if(l>r) swap(l, r);
		for1(i, l, r) ck[i][x][y]=true;
	}
	for1(i, 1, t) for1(j, i, t) d[i][j]=getans(i, j);
	for1(i, 1, t) {
		f[i]=d[1][i]*i*v+k;
		for2(j, 1, i) if(d[j+1][i]!=oo && f[i]>(f[j]+k+d[j+1][i]*(i-j)*v))
			f[i]=f[j]+k+d[j+1][i]*(i-j)*v;
	}
	print(f[t]);
	return 0;
}

