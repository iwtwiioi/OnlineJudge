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
int a[N], op[N], n, m, b[N];

int main() {
	read(n); read(m);
	char s[10];
	for1(i, 1, n) {
		scanf("%s", s);
		read(a[i]);
		if(s[0]=='A') op[i]=1;
		else if(s[0]=='O') op[i]=2;
		else if(s[0]=='X') op[i]=3;
	}
	int ans=0, now=0;
	for3(k, 30, 0) {
		int t=1, t2=now+(1<<k), mx=-1, flag=0;
		if(t2>m) t=0;
		for1(j, 0, t) {
			if(j) t2=(1<<k);
			else t2=0;
			for1(i, 1, n) {
				if(op[i]==1) t2=a[i]&t2;
				else if(op[i]==2) t2=a[i]|t2;
				else if(op[i]==3) t2=a[i]^t2;
			}
			if((t2&(1<<k))>mx) {
				flag=j;
				mx=t2&(1<<k);
			}
		}
		if(flag) now+=(1<<k);
		ans+=mx;
	}
	print(ans);
	return 0;
}