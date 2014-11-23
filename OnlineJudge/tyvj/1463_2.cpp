#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
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

const int N=1000005;
int n, a[N], siz, lst[N];
int ifind(const int &x) {
	if(x<a[1]) return 1;
	for1(i, 1, siz+1) if(lst[i]>=x) {
		int ret=(i-1)*siz, j=0;
		while(a[ret+j]<x) ++j;
		return ret+j;
	}
	return n+1;
}
int main() {
	read(n);
	for1(i, 1, n) read(a[i]);
	sort(a+1, a+1+n);
	siz=sqrt(n);
	for1(i, 1, siz) lst[i]=a[i*siz];
	lst[siz+1]=a[n];
	int x;
	while(~scanf("%d", &x)) printf("%d\n", ifind(x));
	return 0;
}

