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

const int N=10005;
struct dat { int x, y; }a[N];
bool cmp(const dat &a, const dat &b) { return a.x<b.x; }
int n, l;

int main() {
	read(n); read(l); 
	for1(i, 1, n) read(a[i].x), read(a[i].y);
	sort(a+1, a+1+n, cmp);
	int ans=0, now=0;
	for1(i, 1, n) {
		if(now>=a[i].y) continue;
		now=max(now, a[i].x);
		int t=a[i].y-now, t2=t/l;
		if(t%l==0) ans+=t2, now+=t2*l;
		else ans+=t2+1, now+=(t2+1)*l;
	}
	print(ans);
	return 0;
}

