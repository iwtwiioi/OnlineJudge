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
#define printarr(a, n, m) rep(aaa, n) { rep(bbb, m) cout << a[aaa][bbb]; cout << endl; }
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=200;
int n, m, ihead[N], cnt, vis[N], d[N], fa[N];
struct ED { int to, w, next; }e[N*N];
inline void add(const int &u, const int &v, const int &w) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v; e[cnt].w=w;
}

int main() {
	int c=getint(), x, y, w, mini, ans=0, fa;
	while(c--) {
		read(n); read(m);
		CC(ihead, 0);
		CC(vis, 0);
		CC(d, 0x7f);
		rep(i, m) {
			read(x); read(y); read(w);
			add(x, y, w);
		}
		d[1]=0; p[1]=1; q.push(1);
		for2(i, 1, n) {
			min=~0u>>1;
			for1(i, 1, n) if(!vis[i] && d[i]<mini) mini=d[i], y=i;
			vis[y]=1; ans+=mini;
			fa=p[y];
		}
	}
	return 0;
}

