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

const int N=50005;
int ihead[N], cnt, n, d[N][2];
struct ED { int to, next; }e[N<<1];
void add(int u, int v) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v;
	e[++cnt].next=ihead[v]; ihead[v]=cnt; e[cnt].to=u;
}
void dfs(int x, int fa) {
	int y;
	d[x][1]=1;
	for(int i=ihead[x]; i; i=e[i].next) if((y=e[i].to)!=fa) {
		dfs(y, x);
		d[x][1]+=d[y][0];
		d[x][0]+=max(d[y][0], d[y][1]);
	}
}
int main() {
	read(n);
	rep(i, n-1) add(getint(), getint());
	dfs(1, 0);
	print(max(d[1][0], d[1][1]));
	return 0;
}