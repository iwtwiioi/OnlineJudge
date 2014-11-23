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

const int N=3000015;
bool isnotprime[N];
int prime[N], phi[N], cnt;
void init() {
	phi[1]=1;
	for1(i, 2, N-1) {
		if(!isnotprime[i]) prime[++cnt]=i, phi[i]=i-1;
		for(int j=1; j<=cnt && i*prime[j]<=N-1; ++j) {
			int p=prime[j];
			isnotprime[i*p]=1;
			if(i%p==0) { phi[i*p]=phi[i]*p; break; }
			else phi[i*p]=phi[i]*phi[p];
		}
	}
}

int main() {
	int l, r; init();
	while(~scanf("%d%d", &l, &r)) {
		long long ans=0;
		for1(i, l, r) ans+=phi[i];
		printf("%I64d\n", ans);
	}
	return 0;
}