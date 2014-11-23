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

const int M=1005;
int n, k;
int f[M][M];

void add(int a[], int b[]) {
	int lena=a[0], lenb=b[0], lenc=max(lena, lenb);
	int k=0, i;
	for(i=1; i<=lenc || k; ++i) {
		k=(a[i]+b[i])/10;
		a[i]+=b[i]; a[i]%=10;
		a[i+1]+=k;
	}
	a[0]=i-1;
}

int main() {
	read(n); read(k);
	f[0][1]=f[0][0]=1;
	for1(i, 1, k) {
		for1(j, i, n)
			add(f[j], f[j-i]);
	}
	int t=f[n][0];
	for3(i, t, 1) print(f[n][i]);
	return 0;
}

