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

const int N=10005, M=N*50, oo=~0u>>2;
int ihead[N], cnt, n, h, vis[N], d[N], q[N], tail, front;
struct ED { int to, next; }e[M];
struct nd { int x, y, id; }a[N];
bool cmp(const nd &a, const nd &b) { return a.x<b.x; }
bool cmp2(const nd &a, const nd &b) { return a.y<b.y; }
void add(int u, int v) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v;
}
void spfa(int s) {
	for1(i, 1, n+1) d[i]=oo;
	vis[s]=1; q[tail++]=s;
	while(tail!=front) {
		int u=q[front++], v; if(front==N) front=0; vis[u]=0;
		for(int i=ihead[u]; i; i=e[i].next) if(d[v=e[i].to]>d[u]+1) {
			d[v]=d[u]+1;
			if(!vis[v]) {
				vis[v]=1;
				q[tail++]=v; if(tail==N) tail=0;
			}
		}
	}
}

inline int dis(const nd &x, const nd &y) {
	return (x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y);
}
int main() {
	read(h); read(n);
	int S=0, T=n+1;
	for1(i, 1, n) read(a[i].x), read(a[i].y), a[i].id=i;
	sort(a+1, a+1+n, cmp2);
	for1(i, 1, n) if(a[i].y<=1000) add(S, a[i].id); else break;
	for3(i, n, 1) if(a[i].y>=h-1000) add(a[i].id, T); else break;
	sort(a+1, a+1+n, cmp);
	for1(i, 1, n) {
		int l, r;
		for(l=i-1; l>=1; --l) if(a[i].x-a[l].x>1000) break; if(l!=1) ++l;
		for(r=i+1; r<=n; ++r) if(a[r].x-a[i].x>1000) break; if(r!=n) --r;
		for1(j, l, r) if(i!=j && dis(a[i], a[j])<=1000000) {
			add(a[i].id, a[j].id);
		}
	}
	spfa(S);
	int ans=d[T];
	if(ans==oo) ans=-1;
	print(ans-1);
	return 0;
}

