#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
#define pii pair<int, int>
#define mkpii make_pair<int, int>
#define pdi pair<double, int>
#define mkpdi make_pair<double, int>
#define pli pair<ll, int>
#define mkpli make_pair<ll, int>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define for1(i,a,n) for(int i=(a);i<=(n);++i)
#define for2(i,a,n) for(int i=(a);i<(n);++i)
#define for3(i,a,n) for(int i=(a);i>=(n);--i)
#define for4(i,a,n) for(int i=(a);i>(n);--i)
#define CC(i,a) memset(i,a,sizeof(i))
#define read(a) a=getint()
#define print(a) printf("%d", a)
#define dbg(x) cout << (#x) << " = " << (x) << endl
#define error(x) (!(x)?puts("error"):0)
#define printarr2(a, b, c) for1(_, 1, b) { for1(__, 1, c) cout << a[_][__]; cout << endl; }
#define printarr1(a, b) for1(_, 1, b) cout << a[_] << '\t'; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=100015;
int ihead[N], cnt, m, n, num[N], q[N], vis[N], cir, sum, ans;
struct dat { int next, to, w; }e[N*10*2];
void add(int u, int v, int w) { e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v; e[cnt].w=w; }
inline const int gcd(const int &a, const int &b) { return b?gcd(b, a%b):a; }

int main() {
	read(n); read(m);
	for1(i, 1, m) { int u=getint(), v=getint(); add(u, v, 1); add(v, u, -1); }
	for1(k, 1, n) if(!vis[k]) {
		int front=0, tail=0;
		q[tail++]=k;
		int mx=0, mn=0;
		while(front!=tail) {
			int x=q[front++]; if(front==N) front=0;
			mx=max(mx, num[x]);
			mn=min(mn, num[x]);
			for(int i=ihead[x]; i; i=e[i].next) {
				int y=e[i].to;
				if(vis[y]) cir=gcd(cir, abs(num[x]+e[i].w-num[y])), mx=max(mx, num[y]);
				else {
					q[tail++]=y; if(tail==N) tail=0;
					num[y]=num[x]+e[i].w;
					vis[y]=1;
				}
			}
		}
		sum+=mx-mn+1;
	}
	if(cir && cir<3) return puts("-1 -1"), 0;
	if(cir) { int i=3; while(cir%i) ++i; printf("%d %d\n", cir, i); return 0; }
	if(sum<3) return puts("-1 -1"), 0;
	printf("%d 3\n", sum);
	return 0;
}