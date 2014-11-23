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

const int N=105;
bool del[N][N], vis[N];
int ly[N], lx[N], n;
const bool ifind(const int &x) {
	for1(y, 1, n) if(!del[x][y] && !vis[y]) {
		vis[y]=1;
		if(!ly[y] || ifind(ly[y])) {
			lx[x]=y;
			ly[y]=x;
			return true;
		}
	}
	return false;
}
int main() {
	read(n);
	int u, v, ans=0, flag=1;
	for(u=getint(), v=getint(); u&&v; u=getint(), v=getint()) del[u][v]=1;
	for1(i, 1, n) {
		CC(vis, 0);
		if(ifind(i)) ++ans;
	}
	if(ans!=n) puts("none");
	else {
		for1(i, 1, n) {
			v=lx[i];
			del[i][v]=1;
			ly[v]=0;
			CC(vis, 0);
			if(!ifind(i)) {
				printf("%d %d\n", i, v);
				flag=0; ly[v]=i;
			}
			del[i][v]=0;
		}
		if(flag) puts("none");
	}
	return 0;
}

