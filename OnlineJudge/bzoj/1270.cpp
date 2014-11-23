#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define for1(i,a,n) for(i=a;i<=n;++i)
#define for2(i,a,n) for(i=a;i<n;++i)
#define for3(i,a,n) for(i=a;i>=n;--i)
#define for4(i,a,n) for(i=a;i>n;--i)
#define CC(i,a) memset(i,a,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define read(a) scanf("%d", &a)
#define print(a) printf("%d", a)

inline int getnum() {
	int ret=0; char c; 
	for(c=getchar(); c<'0' || c>'9'; c=getchar());
	for(; c>='0' && c<='9'; c=getchar()) ret=ret*10+c-'0';
	return ret;
}

const int N=5005;

int imap[N][N];
int d[N], maxi[N];

int main() {
	int n, h, de, i, j, t, ans=0;
	n=getnum(); h=getnum(); de=getnum();
	for1(i, 1, n) {
		t=getnum();
		for1(j, 1, t)
			++imap[getnum()][i];
	}
	for3(i, h, 1) {
		for1(j, 1, n) {
			d[j]=max(d[j], maxi[i+de])+imap[i][j];
			maxi[i]=max(maxi[i], d[j]);
		}
		ans=max(ans, maxi[i]);
	}
	print(ans);
	return 0;
}

