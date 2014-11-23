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

const int L=305, N=606;
int f[L], n, m, len[N];
char a[N][30], b[L];
int check(int x, int y) {
	if(len[x]+y-1>=m) return -1;
	int tot=0, i=0, ln=len[x];
	while(y<m) {
		if(a[x][i]==b[y]) ++i;
		else ++tot;
		if(i==ln) return tot;
		++y;
	}
	return -1;
}
int main() {
	read(n); read(m);
	scanf("%s", b);
	for1(i, 1, n) {
		scanf("%s", a[i]);
		len[i]=strlen(a[i]);
	}
	for3(i, m-1, 0) {
		f[i]=f[i+1]+1;
		for1(j, 1, n) if(a[j][0]==b[i]) {
			int t=check(j, i);
			if(t==-1) continue;
			f[i]=min(f[i], f[i+len[j]+t]+t);
		}
	}
	printf("%d", f[0]);
	return 0;
}

