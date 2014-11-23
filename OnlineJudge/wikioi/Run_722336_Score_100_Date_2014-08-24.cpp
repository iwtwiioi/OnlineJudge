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

const int N=20005, M=100005, oo=1000000000;
int d1[N], d2[N], q[N+N], front, tail, ihead[N], cnt, n, m, vis[N];
struct ED { int to, next, w; } e[M];
inline void add(const int &u, const int &v, const int &w) { e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v; e[cnt].w=w; }
int spfa() {
	for1(i, 1, n) d1[i]=d2[i]=oo;
	tail=front=d1[1]=0; vis[1]=q[tail++]=1;
	int u, v, w;
	while(tail!=front) {
		u=q[front++]; if(front==N-5) front=0;
		for(int i=ihead[u]; i; i=e[i].next) {
			v=e[i].to, w=e[i].w;
			if(d1[v]>d1[u]+w) {
				d2[v]=d1[v]; d1[v]=d1[u]+w;
				if(!vis[v]) { vis[v]=1; q[tail++]=v; if(tail==N-5) tail=0; }
			}
			else if(d2[v]>d1[u]+w && d1[u]+w>d1[v]) {
				d2[v]=d1[u]+w;
				if(!vis[v]) { vis[v]=1; q[tail++]=v; if(tail==N-5) tail=0; }
			}
			if(d2[v]>d2[u]+w) {
				d2[v]=d2[u]+w;
				if(!vis[v]) { vis[v]=1; q[tail++]=v; if(tail==N-5) tail=0; }
			}
		}
		vis[u]=0;
	}
	if(d2[n]==oo) return -1;
	return d2[n];
}

int main() {
	read(n); read(m);
	int x, y, z;
	rep(i, m) {
		read(x); read(y); read(z);
		add(x, y, z);
	}
	printf("%d\n", spfa());
	return 0;
}

