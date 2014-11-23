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
inline int ctoi(char x) { return x-'0'; }

int main() {
	scanf("%s", s+2); s[0]=s[1]='0';
	int len=strlen(s+2);

	if(ctoi(s[len+1])%2==0) puts("1");
	else puts("0");

	int ans=0;
	for1(i, 2, len+1) ans+=ctoi(s[i]);
	if(ans%3==0) puts("1");
	else puts("0");

	if((ctoi(s[len])*10+ctoi(s[len+1]))%4==0) puts("1");
	else puts("0");

	if((ctoi(s[len-1])*100+ctoi(s[len])*10+ctoi(s[len+1]))%8==0) puts("1");
	else puts("0");

	ans=ctoi(s[len+1]);
	if(ans==1 || ans==4 || ans==9 || ans==6 || ans==5 || ans==0) puts("1");
	else puts("0");

	return 0;
}