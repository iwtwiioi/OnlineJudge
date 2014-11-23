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
#define printarr2(a, b, c) for1(_, 1, b) { for1(__, 1, c) cout << a[_][__] << '\t'; cout << endl; }
#define printarr1(a, b) for1(_, 1, b) cout << a[_] << '\t'; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=1005, oo=~0u>>1;
int a[N][N], n, m, s, ans=oo, t[2][N][N], mm[2][N][N], q[N], front, tail;
inline int check(const int &a, const int &b, const int &flag) { return flag?max(a, b):min(a, b); }
inline bool cmp(const int &a, const int &b, const int &flag) { return flag?a>=b:a<=b; }
void do1(int flag) {
	for1(i, 1, n) {
		front=tail=0;
		for1(j, 1, m) {
			t[flag][i][j]=a[i][j];
			while(front!=tail && j-q[front]+1>s) ++front;
			if(front!=tail) t[flag][i][j]=check(a[i][q[front]], t[flag][i][j], flag);
			while(front!=tail && cmp(a[i][q[tail-1]], a[i][j], !flag)) --tail;
			q[tail++]=j;
		}
	}
}
void do2(int flag) {
	for1(j, s, m) {
		front=tail=0;
		for1(i, 1, n) {
			mm[flag][i][j]=t[flag][i][j];
			while(front!=tail && i-q[front]+1>s) ++front;
			if(front!=tail) mm[flag][i][j]=check(t[flag][q[front]][j], mm[flag][i][j], flag);
			while(front!=tail && cmp(t[flag][q[tail-1]][j], t[flag][i][j], !flag)) --tail;
			q[tail++]=i;
		}
	}
}
void work() {
	do1(1); do1(0);
	do2(1); do2(0);
	for1(i, s, n) for1(j, s, m) ans=min(ans, mm[1][i][j]-mm[0][i][j]);
}
int main() {
	read(n); read(m); read(s);
	for1(i, 1, n) for1(j, 1, m) read(a[i][j]);
	work();
	print(ans);
	return 0;
}