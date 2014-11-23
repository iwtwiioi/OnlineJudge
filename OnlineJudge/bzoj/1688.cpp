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

const int N=1005, M=70000;
int f[M], tot, n, d, k, b[17], c[N], ans;

bool ck(int i) {
	int s=0;
	while(i) ++s, i-=i&-i;
	return s<=k;
}

int main() {
	read(n); read(d); read(k);
	for1(i, 1, 15) b[i]=1<<(i-1);
	tot=(1<<d)-1;
	for1(i, 1, n) {
		int t=getint();
		while(t--) c[i]+=b[getint()];
	}
	for1(l, 1, n) {
		int t=c[l];
		for3(i, tot, 0)
			f[i|t]=max(f[i|t], f[i]+1);
	}
	for1(i, 0, tot) if(ck(i)) ans=max(ans, f[i]);
	print(ans);
	return 0;
}

