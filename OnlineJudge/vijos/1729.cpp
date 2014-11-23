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
#define dbg(x) cout << (#x) << " = " << (x) << endl
#define printarr2(a, b, c) for1(_, 1, b) { for1(__, 1, c) cout << a[_][__]; cout << endl; }
#define printarr1(a, b) for1(_, 1, b) cout << a[_] << '\t'; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=50;
int ihead[N*N], cnt, ly[N*N], n, m, vis[N][N], ans, ins[N*N];
const int dx[]={-1, -2, -2, -1, 1, 2, 2, 1}, dy[]={-2, -1, 1, 2, 2, 1, -1, -2};
struct ED { int next, to; }e[(N*N)<<1];
struct dat{ int x, y; }a[N*N];
void add(int u, int v) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v;
}
bool ifind(int x) {
	int y;
	for(int i=ihead[x]; i; i=e[i].next) if(!ins[y=e[i].to]) {
		ins[y]=1;
		if(!ly[y] || ifind(ly[y])) {
			ly[y]=x;
			return true;
		}
	}
	return false;
}

int main() {
	read(n); read(m);
	char s[10];
	for1(i, 1, m) {
		scanf("%s", s+1);
		a[i].x=s[1]-'A'+1;
		int len=strlen(s+1);
		for1(j, 2, len) {
			a[i].y*=10;
			a[i].y+=s[j]-'0';
		}
		vis[a[i].x][a[i].y]=i;
	}
	for1(i, 1, m) {
		rep(k, 8) {
			int fx=dx[k]+a[i].x, fy=dy[k]+a[i].y;
			if(fx<1 || fy<1 || fx>n || fy>n || !vis[fx][fy]) continue;
			add(i, vis[fx][fy]);
		}
	}
	for1(i, 1, m) if((a[i].x+a[i].y)&1) {
		CC(ins, 0);
		if(ifind(i)) ++ans;
	}
	printf("%d\n", ans);
	return 0;
}