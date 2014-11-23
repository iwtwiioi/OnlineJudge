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
#define dbg(x) cout << #x << " = " << x << endl
#define printarr2(a, b, c) for1(i, 1, b) { for1(j, 1, c) cout << a[i][j]; cout << endl; }
#define printarr1(a, b) for1(i, 1, b) cout << a[i]; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=2005;
int p[N], n, c, cnt, ans;
struct ED { int x, y, w; }e[N*N];
struct dat { int x, y; }a[N];
bool cmp(const ED &a, const ED &b) { return a.w<b.w; }
inline int dis(dat &a, dat &b) { return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y); }
const int ifind(const int &x) { return x==p[x]?x:p[x]=ifind(p[x]); }

int main() {
	read(n); read(c);
	for1(i, 1, n) read(a[i].x), read(a[i].y);
	for1(i, 1, n) for1(j, 1, n) if(i!=j) {
		e[++cnt].x=i, e[cnt].y=j;
		e[cnt].w=dis(a[i], a[j]);
	}
	sort(e+1, e+1+cnt, cmp);
	int tot=0;
	for1(i, 1, n) p[i]=i;
	for1(i, 1, cnt) {
		if(e[i].w>=c) {
			int fx=ifind(e[i].x), fy=ifind(e[i].y);
			if(fx!=fy) {
				p[fx]=fy;
				ans+=e[i].w;
			++tot;
			}
		}
	}
	if(tot<n-1) puts("-1");
	else print(ans);
	return 0;
}