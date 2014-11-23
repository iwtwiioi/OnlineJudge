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

const int N=205;
const double eps=1e-10, oo=1e15;
int n, x[N], y[N], cnt, ans;
double k[N*N];

int main() {
	read(n);
	for1(i, 1, n) { read(x[i]); read(y[i]); }
	for1(i, 1, n-1) for1(j, i+1, n) 
		if(x[i]!=x[j]) k[++cnt]=(double)(y[i]-y[j])/(x[i]-x[j]);
		else k[++cnt]=oo;
	sort(k+1, k+1+cnt);
	for1(i, 1, cnt) if(abs(k[i]-k[i-1])>eps) ++ans;
	print(ans);
	return 0;
}

