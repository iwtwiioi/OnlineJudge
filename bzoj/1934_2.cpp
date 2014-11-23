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

const int N=310, M=N*N/2, oo=~0u>>1;
int ihead[N], cnt=1, n, m, ly[N], x[N], cx, y[N], cy, vis[N];
struct ED { int from, to, cap, next; } e[M];
inline void add(const int &u, const int &v) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v;
	e[++cnt].next=ihead[v]; ihead[v]=cnt; e[cnt].to=u;
}
const bool ifind(const int &x) {
	vis[x]=1; int y;
	for(int i=ihead[x]; i; i=e[i].next) if(!vis[y=e[i].to]) {
		vis[y]=1;
		if(!ly[y] || ifind(ly[y])) {
			ly[y]=x;
			return true;
		}
	}
	return false;
}
int main() {
	read(n); read(m);
	int t, ans=0;
	for1(i, 1, n) {
		read(t);
		if(t) x[++cx]=i;
		else y[++cy]=i;
	}
	rep(i, m) add(getint(), getint());
	for1(i, 1, cx) {
		CC(vis, 0);
		if(ifind(x[i])) ++ans;
	}
	print(ans);
	return 0;
}
