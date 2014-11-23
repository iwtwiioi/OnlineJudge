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
#define printarr(a, n, m) rep(aaa, n) { rep(bbb, m) cout << a[aaa][bbb]; cout << endl; }
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=5050;
const long long oo=~0ull>>2;
int m, n, vis[N], q[N], front, tail, ihead[N], cnt;
long long d[N], d2[N];
struct ED { int to, next; long long w; }e[200010];
inline void add(const int &u, const int &v, const int &w) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v; e[cnt].w=w;
}
long long spfa(const int &s, const int &t) {
	for1(i, 0, t) d[i]=d2[i]=oo;
	d[s]=front=tail=0; vis[s]=1;  q[tail++]=s;
	int u, v, w;
	while(front!=tail) {
		u=q[front++]; if(front==N) front=0; vis[u]=0;
		for(int i=ihead[u]; i; i=e[i].next) {
			v=e[i].to; w=e[i].w;
			if(d[v]>d[u]+w) {
				d2[v]=d[v]; d[v]=d[u]+w;
				if(!vis[v]) { vis[v]=1; q[tail++]=v; if(tail==N) tail=0; }
			}
			else if(d2[v]>d[u]+w && d[v]<d[u]+w) {
				d2[v]=d[u]+w;
				if(!vis[v]) { vis[v]=1; q[tail++]=v; if(tail==N) tail=0; }
			}
			if(d2[v]>d2[u]+w) {
				d2[v]=d2[u]+w;
				if(!vis[v]) { vis[v]=1; q[tail++]=v; if(tail==N) tail=0; }
			}
		}
	}
	if(d2[t]!=oo) return d2[t];
	return -1;
}

int main() {
	read(n); read(m);
	int x, y, z;
	rep(i, m) {
		read(x); read(y); read(z);
		add(x, y, z); add(y, x, z);
	}
	printf("%lld", spfa(1, n));
	return 0;
}

