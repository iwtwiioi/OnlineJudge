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

const int N=105, K=105, E=400;
int n, k, e;
int f[K];
struct dat { int x, f, c; }a[N];

int main() {
	read(k); read(e); read(n);
	for1(i, 1, n) read(a[i].x), read(a[i].f), read(a[i].c);
	CC(f, 0x3f); f[0]=0;
	for1(p, 0, e) {
		for1(j, 1, k) f[j]+=j;
		for1(i, 1, n) if(a[i].x==p) {
			for3(j, k, 1) {
				for1(l, 1, a[i].f) if(j-l>=0)
					f[j]=min(f[j], f[j-l]+l*a[i].c);
			}
		}
	}
	print(f[k]);
	return 0;
}

