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
const int N=10005;
int n, a[N], b[N], vis[N], pos[N], ans;
const bool cmp(const int &x, const int &y) { return a[x]<a[y]; }
int main() {
	read(n);
	for1(i, 1, n) read(a[i]), b[i]=i;
	sort(b+1, b+1+n, cmp);
	int mn=a[b[1]];
	for1(i, 1, n) pos[b[i]]=i;
	for1(i, 1, n) if(!vis[i]) {
		int j=i, mini=~0u>>1, sum=0, len=0;
		while(!vis[j]) {
			++len;
			mini=min(mini, a[j]);
			sum+=a[j];
			vis[j]=1;
			j=pos[j];
		}
		ans+=sum+min((len-2)*mini, (len+1)*mn+mini);
	}
	print(ans);
	return 0;
}

