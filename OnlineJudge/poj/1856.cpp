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

const int N=500005, oo=~0u>>1;
int a[N], L[N], R[N];
long long cnt;
void gb(int l, int r) {
	if(l<r-1) {
		int m=(l+r)>>1, i, j;
		gb(l, m); gb(m, r);
		for(i=0; i<m-l; ++i) L[i]=a[l+i];
		for(j=0; j<r-m; ++j) R[j]=a[m+j];
		L[i]=R[j]=-oo; i=j=0;
		while(l<r) {
			if(L[i]>R[j]) {
				a[l++]=L[i++];
				cnt+=r-m-j;
			}
			else a[l++]=R[j++];
		}
	}
}
int main() {
	int n;
	while(scanf("%d", &n) && n) {
		cnt=0;
		rep(i, n) read(a[i]);
		gb(0, n);
		printf("%lld\n", cnt);
	}
	return 0;
}

