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
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }

const int N=65;
int a[N], s[N], vis[N], R, B, G, n, m, f[22][22][22], p, ans;
void add(int &a, const int &b) { a=(a+b)%p; a=(a+p)%p; }
int mpow(int a, int b) {
	int ret=1;
	for(; b; a=(a*a)%p, b>>=1) if(b&1) ret=(ret*a)%p;
	return ret;
}
int getans() {
	CC(f, 0); CC(s, 0); CC(vis, 0); int cnt=0;
	for1(i, 1, n) if(!vis[i]) { ++cnt; for(int x=i; !vis[x]; x=a[x]) vis[x]=1, ++s[cnt]; }
	f[0][0][0]=1;
	for1(i, 1, cnt) for3(r, R, 0) for3(b, B, 0) for3(g, G, 0) {
		if(r-s[i]>=0) add(f[r][b][g], f[r-s[i]][b][g]);
		if(b-s[i]>=0) add(f[r][b][g], f[r][b-s[i]][g]);
		if(g-s[i]>=0) add(f[r][b][g], f[r][b][g-s[i]]);
	}
	return f[R][B][G];
}
int main() {
	read(R); read(B); read(G); read(m); read(p); n=R+B+G;
	for1(i, 1, m) { for1(i, 1, n) read(a[i]); add(ans, getans()); }
	for1(i, 1, n) a[i]=i;
	add(ans, getans());
	ans*=mpow(m+1, p-2);
	printf("%d\n", ans%p);
	return 0;
}