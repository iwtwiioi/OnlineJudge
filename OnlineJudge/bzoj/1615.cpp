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

const int N=1105;
struct dat { int x, y, r; double w; }a[N];
bool vis[N];
int q[N], front, tail, X, Y, n, id;
double d[N], ans[N];
double dis(const dat &x, const dat &y) { return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y)); }

int main() {
	read(n); read(X); read(Y);
	for1(i, 1, n) { 
		read(a[i].x), read(a[i].y), read(a[i].r);
		if(a[i].x==0 && a[i].y==0) id=i;
	}
	vis[id]=1; q[tail++]=id; d[id]=ans[id]=10000;
	while(front!=tail) {
		int x=q[front++]; if(front==N) front=0;
		if(a[x].x==X && a[x].y==Y) { printf("%d", abs((int)ans[x])); break; }
		for1(i, 1, n) if(!vis[i] && abs(dis(a[x], a[i])-(a[x].r+a[i].r))<1e-8) {
			d[i]=-d[x]*a[x].r/a[i].r;
			ans[i]+=abs(d[i])+ans[x];
			vis[i]=1;
			q[tail++]=i; if(tail==N) tail=0;
		}
	}
	return 0;
}

