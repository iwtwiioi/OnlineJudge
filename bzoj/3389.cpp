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
#define printarr2(a, b, c) for1(i, 1, b) { for1(j, 1, c) cout << a[i][j]; cout << endl; }
#define printarr1(a, b) for1(i, 1, b) cout << a[i]; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=25005;
int n, t, cnt;
struct dat { int x, y; }a[N];
bool cmp(const dat &a, const dat &b) { return a.x==b.x?a.y<b.y:a.x<b.x; }

int main() {
	read(n); read(t);
	for1(i, 1, n) read(a[i].x), read(a[i].y);
	sort(a+1, a+1+n, cmp);
	a[n+1].x=100055050;
	for1(i, 1, n) if(a[i].x!=a[i+1].x) a[++cnt]=a[i];
	if(a[1].x>1) { puts("-1"); return 0; }
	int ans=1, now=1;
	for1(i, 1, cnt) {
		int fix=0, nx=now, pos=0, ed=a[now].y;
		while(nx<cnt && a[nx+1].x<=ed+1) {
			++nx;
			if(a[nx].y>ed && fix<a[nx].y) {
				fix=a[nx].y;
				pos=nx;
			}
		}
		if(a[now].y==t) break;
		if(nx==now || fix==0) { puts("-1"); return 0; }
		now=pos;
		i=nx;
		++ans;
	}
	if(a[now].y!=t) puts("-1");
	else print(ans);
	return 0;
}