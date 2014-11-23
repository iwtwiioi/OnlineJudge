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

const int N=6005;
struct point { double x, y; }a[N], s[N];
typedef point dat;
dat operator-(const point &a, const point &b) { return (dat){a.x-b.x, a.y-b.y}; }
double cross(const dat &a, const dat &b) { return a.x*b.y-a.y*b.x; }
bool cmp(const point &a, const point &b) { return a.x==b.x?a.y<b.y:a.x<b.x; }
int top, n;
double ans;

void getans() {
	sort(a+1, a+n+1, cmp);
	for1(i, 1, n) {
		while(top>1 && cross(s[top]-s[top-1], a[i]-s[top-1])<=0) --top;
		s[++top]=a[i];
	}
	int t=top;
	for3(i, n-1, 1) {
		while(top>t && cross(s[top]-s[top-1], a[i]-s[top-1])<=0) --top;
		s[++top]=a[i];
	}
	if(n>1) --top;
}
inline double dis(const point &a, const point &b) { return (double)sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)); }

int main() {
	read(n);
	for1(i, 1, n) read(a[i].x), read(a[i].y);
	getans();
	for1(i, 1, top) ans+=dis(s[i], s[i+1]);
	printf("%.2lf", ans);
	return 0;
}

