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

const int N=25;
int n, l, r;
int ans, c;
struct dat { int x, y; }a[N];
bool operator < (const dat &a, const dat &b) { return a.x<b.x; }

bool ask() {
	int sum=0;
	for3(i, r, l) {
		int t=(c-sum)/a[i].x;
		t=min(t, a[i].y);
		sum+=t*a[i].x; a[i].y-=t;
		if(sum==c) return 1;
	}
	if(sum==c) return 1;
	while(a[l].y==0 && l<=r) ++l;
	while(a[r].y==0 && l<=r) --r;
	if(l>r) return 0;
	while(l<=r && sum<c) {
		int t=(c-sum+a[l].x-1)/a[l].x;
		if(t<=a[l].y) { a[l].y-=t; return 1; }
		else { sum+=a[l].y*a[l].x; a[l].y=0; ++l; }
	}
	if(sum<c) return 0;
	return 1;
}
int main() {
	read(n); read(c);
	for1(i, 1, n) read(a[i].x), read(a[i].y);
	sort(a+1, a+1+n);
	l=1; r=n;
	while(a[r].x>=c && l<=r) ans+=a[r].y, a[r].y=0, --r;
	while(ask()) ++ans;
	printf("%d", ans);
	return 0;
}

