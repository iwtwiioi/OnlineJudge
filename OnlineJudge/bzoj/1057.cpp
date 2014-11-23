#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
#define pii pair<int, int>
#define mkpii make_pair<int, int>
#define pdi pair<double, int>
#define mkpdi make_pair<double, int>
#define pli pair<ll, int>
#define mkpli make_pair<ll, int>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define for1(i,a,n) for(int i=(a);i<=(n);++i)
#define for2(i,a,n) for(int i=(a);i<(n);++i)
#define for3(i,a,n) for(int i=(a);i>=(n);--i)
#define for4(i,a,n) for(int i=(a);i>(n);--i)
#define CC(i,a) memset(i,a,sizeof(i))
#define read(a) a=getint()
#define print(a) printf("%d", a)
#define dbg(x) cout << (#x) << " = " << (x) << endl
#define error(x) (!(x)?puts("error"):0)
#define printarr2(a, b, c) for1(_, 1, b) { for1(__, 1, c) cout << a[_][__]; cout << endl; }
#define printarr1(a, b) for1(_, 1, b) cout << a[_] << '\t'; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=2005;
int a[N][N], len[N], sum[N][N], s[N], top, n, m, ans1, ans2;

inline int sqr(const int &a) { return a*a; }
void work(int h[N], int b[N]) {
	top=0; len[top]=0;
	for1(i, 1, m) {
		int nl=0;
		if(top) {
			if(b[s[top]]==b[i]) {
				int l=0;
				while(top) {
					l+=len[top];
					ans2=max(ans2, l*h[s[top]]);  
					ans1=max(ans1, sqr(min(l, h[s[top]])));
					--top;
				}
			}
			else {
				int l=0;
				while(top && h[s[top]]>h[i]) {
					l+=len[top];
					ans2=max(ans2, l*h[s[top]]);
					ans1=max(ans1, sqr(min(l, h[s[top]])));
					--top;
				}
				nl=l;
			}
		}
		s[++top]=i;
		len[top]=nl+1;
	}
	int l=0;
	while(top) {
		l+=len[top]; //printf("id:%d\tlen:%d\th:%d\n", s[top], len[top], h[s[top]]);
		ans2=max(ans2, l*h[s[top]]);
		ans1=max(ans1, sqr(min(l, h[s[top]])));
		--top;
	}
}

int main() {
	read(n); read(m);
	CC(a, -1);
	for1(i, 1, n) for1(j, 1, m) read(a[i][j]);
	for1(j, 1, m) for1(i, 1, n) if(a[i][j]!=a[i-1][j]) sum[i][j]=sum[i-1][j]+1; else sum[i][j]=1;
	for1(i, 1, n) work(sum[i], a[i]);
	printf("%d\n%d\n", ans1, ans2);
	return 0;
}