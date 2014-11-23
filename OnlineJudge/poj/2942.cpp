#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <vector>
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

const int N=1005, M=1000005;
int ihead[N], n, m, cnt, LL[N], FF[N], mp[N][N], tot, s[M<<1], top, vis[N], ok[N], col[N];
struct ED { int from, to, next; } e[M<<1];
void add(int u, int v) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v; e[cnt].from=u;
	e[++cnt].next=ihead[v]; ihead[v]=cnt; e[cnt].to=u; e[cnt].from=v;
}
bool ifind(int u) {
	int v;
	for(int i=ihead[u]; i; i=e[i].next) if(vis[v=e[i].to]) {
		if(col[v]==-1) { col[v]=!col[u]; return ifind(v); }
		else if(col[v]==col[u]) return true;
	}
	return false;
}
void color(int x) {
	int y, u=e[x].from;
	CC(vis, 0); CC(col, -1); col[u]=0;
	do {
		y=s[top--];
		vis[e[y].from]=vis[e[y].to]=1;
	} while(y!=x);
	if(ifind(u)) for1(i, 1, n) if(vis[i]) ok[i]=1;
}
void tarjan(int u, int fa) {
	FF[u]=LL[u]=++tot;
	for(int i=ihead[u]; i; i=e[i].next) if(fa!=e[i].to) {
		int v=e[i].to;
		if(!FF[v]) {
			s[++top]=i; //入栈这里要注意。。不要在上边入栈。。
			tarjan(v, u);
			if(LL[v]>=FF[u]) color(i);
			LL[u]=min(LL[u], LL[v]);
		}
		else if(LL[u]>FF[v]) s[++top]=i, LL[u]=FF[v]; //入栈这里要注意。。
	}
}
int main() {
	while(1) {
		read(n); read(m); int ans=0;
		if(n==0 && m==0) break;
		CC(mp, 0); CC(ihead, 0); CC(LL, 0); CC(FF, 0); CC(ok, 0); top=cnt=tot=0;
		rep(i, m) {
			int u=getint(), v=getint();
			mp[u][v]=mp[v][u]=1;
		}
		for1(i, 1, n) for1(j, i+1, n) if(!mp[i][j]) add(i, j);
		for1(i, 1, n) if(!FF[i]) tarjan(i, -1);
		for1(i, 1, n) if(!ok[i]) ++ans;
		printf("%d\n", ans);
	}
	return 0;
}