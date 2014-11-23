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
#define printarr2(a, b, c) for1(i, 1, b) { for1(j, 1, c) cout << a[i][j] << ' '; cout << endl; }
#define printarr1(a, b) for1(i, 1, b) cout << a[i] << ' '; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=50005;
int q[N], front, tail, n, d, mx[2][N];
struct dat { int x, h; }a[N];
bool cmp(const dat &a, const dat &b) { return a.x<b.x; }
void work(int *arr) {
	front=tail=0;
	for1(i, 1, n) {
		while(front!=tail && abs(a[i].x-a[q[front]].x)>d) ++front;
		if(front!=tail) arr[i]=q[front];
		while(front!=tail && a[i].h>a[q[tail-1]].h) --tail;
		q[tail++]=i;
	}
}

int main() {
	read(n); read(d);
	for1(i, 1, n) read(a[i].x), read(a[i].h);
	sort(a+1, a+1+n, cmp);
	work(mx[0]);
	for1(i, 1, n) if(i<n-i+1) swap(a[i], a[n-i+1]);
	work(mx[1]);
	int ans=0;
	for1(i, 1, n) if(a[mx[1][i]].h>=(a[i].h<<1) && a[n-mx[0][n-i+1]+1].h>=(a[i].h<<1)) ++ans;
	print(ans);
	return 0;
}