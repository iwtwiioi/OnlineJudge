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
#define dbg(x) cout << #x << " = " << x << endl
#define printarr(a, n, m) rep(aaa, n) { rep(bbb, m) cout << a[aaa][bbb]; cout << endl; }
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }
const int N=50005;

struct data { int w, x; }a[N];
int vis[N+N+1], sum=N, n, ans;
bool cmp(const data &a, const data &b) { return a.x<b.x; }

int main() {
	read(n);
	for1(i, 1, n) { read(a[i].w); read(a[i].x); if(!a[i].w) a[i].w=-1; }
	sort(a+1, a+1+n, cmp);
	for1(i, 1, n) {
		sum+=a[i].w;
		if(!vis[sum]) vis[sum]=a[i+1].x;
		else ans=max(ans, a[i].x-vis[sum]);
	}
	print(ans);
	return 0;
}

