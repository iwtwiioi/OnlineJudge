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


char s[150];
int n, len;
int ifind() {
	for1(i, 1, n) if(n%i==0) {
		int beg=i+1;
		while(beg<=n) {
			int flag=0;
			rep(j, i) if(s[beg+j]!=s[j+1]) { flag=1; break; }
			if(flag) break;
			beg+=i;
		}
		if(beg>n) return i;
	}
	return 0;
}
void work(int x) {
	long long now=1;
	for1(i, 1, x) {
		now*=(long long)i;
		//while(now%10==0) now/=10;
	} dbg(now); dbg(x);
	printf("%lld\n", now%10);
}
int main() {
	scanf("%s", s+1);
	n=strlen(s+1);
	len=ifind();
	//work(len);
	int k=1;
	for1(i, 1, 10) k*=i;
	print(k);
	return 0;
}