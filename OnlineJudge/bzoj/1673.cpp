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

const int N=1005;
int n, m, ans=-1;
long long a[N], sum[N];
void dfs(int x, long long tot) {
	if(tot>m) return;
	if(sum[x-1]+tot<=m) {
		ans=max(ans, sum[x-1]+tot);
		return;
	}
	ans=max(ans, tot);
	for1(i, 1, x-1) {
		tot+=a[i];
		dfs(i, tot);
		tot-=a[i];
	}
}
int main() {
	read(n); read(m);
	for1(i, 1, n) read(a[i]), sum[i]=sum[i-1]+a[i];
	dfs(n+1, 0);
	printf("%d", ans);
	return 0;
}

