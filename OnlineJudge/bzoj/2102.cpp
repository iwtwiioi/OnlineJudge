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
#define printarr2(a, b, c) for1(i, 1, b) { for1(j, 1, c) cout << a[i][j]; cout << endl; }
#define printarr1(a, b) for1(i, 1, b) cout << a[i]; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=105;
int n, m, cnt, ans, a[N][N], b[N];

bool check(int t) {
	for1(i, 1, m) {
		int tot=0;
		rep(j, n) if(a[i][j] && (t&(1<<j))) ++tot;
		if(tot!=b[i]) return 0;
	}
	return 1;
}

int main() {
	read(n); read(m);
	for1(i, 1, m) {
		rep(j, n) {
			char ch=getchar(); 
			while(ch<'0'||ch>'9') ch=getchar();
			a[i][j]=ch-'0';
		}
		b[i]=getint();
	}
	int mx=(1<<n)-1, flag=0;
	for1(x, 0, mx) {
		if(check(x)) {
			if(cnt) { puts("NOT UNIQUE"); return 0; }
			flag=1;
			ans=x;
			++cnt;
		}
	}
	if(!flag) puts("IMPOSSIBLE");
	else rep(i, n) printf("%d", (bool)(ans&(1<<i)));
	return 0;
}