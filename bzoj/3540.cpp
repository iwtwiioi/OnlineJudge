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

const int N=100005;
int n, sum=50000, pos[N];
struct dat { int x, a; }a[N];
const bool cmp(const dat &a, const dat &b) { return a.x<b.x; }

int main() {
	read(n); 
	for1(i, 1, n) {
		read(a[i].x);
		char ch=getchar(); while(ch!='W'&&ch!='S') ch=getchar();
		if(ch=='W') a[i].a=1;
		else if(ch=='S') a[i].a=-1;
	}
	int ans=0;
	for1(i, 1, n) {
		sum+=a[i].a; dbg(sum);
		if(sum>=0 && !(sum%1)) {
			ans=max(ans, a[i].x-a[1].x); dbg(a[i].x-a[1].x);
		}
	}
	print(ans);
	return 0;
}