#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <string>
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

using namespace std;

const int N=10005, M=100005, oo=~0u>>1;
int d[N][2], ihead[N], cnt, vis[N], q[N], tail, front, n, m;
struct ED { int to, next, w, jo; } e[M];
inline void add(const int &u, const int &v, const int &w) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v; e[cnt].w=w;
}
inline const void spfa(const int &s) {
	CC(d, 0x3f); CC(vis, 0);
	d[s][1]=d[s][0]=tail=front=0; vis[s]=1; q[tail++]=s;
	int u, v, w;
	while(front!=tail) {
		u=q[front++]; if(front==N) front=0; vis[u]=0;
		for(int i=ihead[u]; i; i=e[i].next) {
			v=e[i].to; w=e[i].w;
			if(e[i].jo==1) {
				if(d[v][0]>d[u][1]+w) {
					d[v][0]=d[u][1]+w;
					if(!vis[v]) { vis[v]=1; q[tail++]=v; if(tail==N) tail=0; }
				}
			}
			else if(e[i].jo==2) {
				if(d[v][1]>d[u][0]+w) {
					d[v][1]=d[u][0]+w;
					if(!vis[v]) { vis[v]=1; q[tail++]=v; if(tail==N) tail=0; }
				}
			}
			else {
				if(d[v][1]>d[u][0]+w) {
					d[v][1]=d[u][0]+w;
					if(!vis[v]) { vis[v]=1; q[tail++]=v; if(tail==N) tail=0; }
				}
				if(d[v][0]>d[u][1]+w) {
					d[v][0]=d[u][1]+w;
					if(!vis[v]) { vis[v]=1; q[tail++]=v; if(tail==N) tail=0; }
				}
			}
		}
	}
}
int main() {
	read(n); read(m);
	int u, v, w, ans=oo;
	char name[30], nm[30];
	while(m--) {
		read(u); read(v); read(w);
		add(v, u, w);
	}
	read(u); while(u--) e[getint()].jo+=1;
	read(u); while(u--) e[getint()].jo+=2;
	spfa(n);
	read(u); while(u--) {
		read(v); scanf("%s", name);
		if(ans>d[v][1]) {
			ans=d[v][1];
			strcpy(nm, name);
		}
	}
	printf("%s\n%d\n", nm, ans);
	return 0;
}
