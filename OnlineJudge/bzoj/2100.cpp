#include <cstdio>
#include <cstring>
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

const int N=100005, M=400005;
int ihead[N], cnt, q[N], front, tail, d[N], n, m, x, xx, xxx;
bool vis[N];
struct ED { int to, next, w; }e[M];
inline void add(const int &u, const int &v, const int &w) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v; e[cnt].w=w;
	e[++cnt].next=ihead[v]; ihead[v]=cnt; e[cnt].to=u; e[cnt].w=w;
}
inline void spfa(const int &s) {
	memset(d, 0x3f, sizeof(int)*(n+3));
	d[s]=0; vis[s]=1; front=tail=0; q[tail++]=s;
	while(tail!=front) {
		int u=q[front++], v; if(front==N) front=0; vis[u]=0;
		for(int i=ihead[u]; i; i=e[i].next) if(d[v=e[i].to]>d[u]+e[i].w) {
			d[v]=d[u]+e[i].w;
			if(!vis[v]) {
				vis[v]=1;
				if(d[v]<d[q[front]]) {
					--front; if(front<0) front+=N;
					q[front]=v;
				}
				else {
					q[tail++]=v; if(tail==N) tail=0;
				}
			}
		}
	}
}
  
int main() {
	read(m); read(n); read(x); read(xx); read(xxx);
	for1(i, 1, m) {
		int u=getint(), v=getint(), w=getint();
		add(u, v, w);
	}
	spfa(xx);
	int ans=d[x]+d[xxx];
	spfa(xxx);
	if(ans>d[x]+d[xx]) ans=d[x]+d[xx];
	print(ans);
	return 0;
}