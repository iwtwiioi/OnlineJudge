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
#define dbg(x) cout << (#x) << " = " << (x) << endl
#define printarr2(a, b, c) for1(_, 1, b) { for1(__, 1, c) cout << a[_][__]; cout << endl; }
#define printarr1(a, b) for1(_, 1, b) cout << a[_] << '\t'; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=1500005;
typedef long long ll;
int ihead[N], cnt, n, d[N][3], f[N][3];
ll MD;
struct ED  { int next, to; }e[N<<1];
void add(int u, int v) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v;
	e[++cnt].next=ihead[v]; ihead[v]=cnt; e[cnt].to=u;
}
inline int mul(ll a, ll b) { return ((a%MD)*(b%MD))%MD; }
void dfs(int x, int fa) {
	d[x][0]=f[x][0]=f[x][1]=f[x][2]=1; int y, flag=0;
	for(int i=ihead[x]; i; i=e[i].next) if((y=e[i].to)!=fa) {
		dfs(y, x);
		d[x][0]+=d[y][2];
		d[x][1]+=max(d[y][0], d[y][1]);
		d[x][2]+=d[y][1];

		f[x][0]=mul(f[x][0], f[y][2]);
		if(d[y][0]==d[y][1])
			f[x][1]=mul(f[x][1], f[y][0]+f[y][1]);
		else if(d[y][0]>d[y][1]) 
			f[x][1]=mul(f[x][1], f[y][0]);
		else 
			f[x][1]=mul(f[x][1], f[y][1]);
		f[x][2]=mul(f[x][2], f[y][1]);
		flag=1;
	}
	if(!flag) d[x][1]=-1000;
}
int main() {
	read(n);
	for1(i, 1, n-1) add(getint(), getint());
	read(MD);
	int root=(n+1)/2;
	dfs(root, -1);
	int who=d[root][1]>d[root][0];
	ll ans=0;
	printf("%d\n", d[root][who]);
	if(d[root][1]==d[root][0]) ans=((ll)f[root][0]+(ll)f[root][1])%MD;
	else ans=f[root][who];
	printf("%lld", ans);
	return 0;
}