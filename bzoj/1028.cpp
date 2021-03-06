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

const int N=505;
int n, m, c[N], ans[N], cnt, b[N];
bool check() {
	for1(j, 1, n) if(b[j]>=2) {
		memcpy(c, b, sizeof b);
		c[j]-=2;
		int flag=1;
		for1(i, 1, n) if(c[i]) {
			if(c[i]<0) { flag=0; break; }
			int t=c[i]%3;
			c[i+1]-=t;
			c[i+2]-=t;
		}
		if(!flag || c[n+1]<0 || c[n+2]<0) continue;
		return 1;
	}
	return 0;
}
int main() {
	read(n); read(m); m=m*3+1;
	for1(i, 1, m) b[getint()]++;
	for1(i, 1, n) {
		b[i]++;
		if(check()) ans[++cnt]=i;
		b[i]--;
	}
	if(cnt==0) { puts("NO"); return 0; }
	printf("%d", ans[1]);
	for1(i, 2, cnt) printf(" %d", ans[i]);
	return 0;
}