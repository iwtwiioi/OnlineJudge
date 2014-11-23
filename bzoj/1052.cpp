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
const int N=40005, oo=~0u>>2;
int n, vis[N];
struct dat { int x, y; }a[N];
void ifind(int &x1, int &y1, int &x2, int &y2) {
	x1=y1=oo; x2=y2=-oo;
	for1(i, 1, n) if(!vis[i]) x1=min(x1, a[i].x), x2=max(x2, a[i].x), y1=min(y1, a[i].y), y2=max(y2, a[i].y);
}
void fix(const int &x1, const int &y1, const int &x2, const int &y2, const int &dep) { for1(i, 1, n) if(!vis[i] && a[i].x>=x1 && a[i].x<=x2 && a[i].y>=y1 && a[i].y<=y2) vis[i]=dep; }
bool find(int dep, const int &L) {
	int x[2], y[2];
	ifind(x[0], y[0], x[1], y[1]);
	if(max(x[1]-x[0], y[1]-y[0])<=L) return true;
	if(dep==3) return false;
	rep(i, 2) rep(j, 2) {
		if(i==0) {
			if(j==0) fix(x[i], y[j], x[i]+L, y[j]+L, dep);
			else fix(x[i], y[j]-L, x[i]+L, y[j], dep);
		}
		else {
			if(j==0) fix(x[i]-L, y[j], x[i], y[j]+L, dep);
			else fix(x[i]-L, y[j]-L, x[i], y[j], dep);
		}
		//printf("dep:%d, (%d,%d), (%d,%d)\n", dep, x[0], y[0], x[1], y[1]);
		//for1(i, 1, n) printf("%d ", vis[i]); puts("");
		if(find(dep+1, L)) return true;
		for1(i, 1, n) if(vis[i]==dep) vis[i]=0;
	}
	return false;
}
bool check(int L) {
	memset(vis, 0, sizeof(int)*(n+2)); //dbg(L);
	return find(1, L);
}

int main() {
	read(n);
	for1(i, 1, n) read(a[i].x), read(a[i].y);
	int x[2], y[2];
	ifind(x[0], y[0], x[1], y[1]);
	int l=1, r=max(x[1]-x[0], y[1]-y[0]);
	while(l<=r) {
		int mid=(l+r)>>1;
		if(check(mid)) r=mid-1;
		else l=mid+1;
	}
	print(r+1);
	return 0;
}