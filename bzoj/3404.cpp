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

const int N=1000005;
bool f[N], vis[N];
bool dfs(int x) {
	if(vis[x]) return f[x];
	if(x==0) return 0;
	vis[x]=1;
	int t=x, mx=0, mn=10;
	while(t) {
		int k=t%10;
		t/=10;
		if(k) mx=max(mx, k), mn=min(mn, k); 
	}
	if(!dfs(x-mn) && !dfs(x-mx)) return f[x]=0;
	return f[x]=1;
}
int main() {
	int n=getint();
	while(n--) {
		int ans=dfs(getint());
		ans?puts("YES"):puts("NO");
	}
	return 0;
}