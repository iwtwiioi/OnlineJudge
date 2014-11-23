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
inline int getnum() { int ret=0; char c; for(c=getchar(); c<'0' || c>'9'; c=getchar()); for(; c>='0' && c<='9'; c=getchar()) ret=ret*10+c-'0'; return ret; }

const int N=1005;
int imap[N][N], l[N][N], r[N][N], L[N][N], R[N][N], h[N][N];

int main() {
	int n, m, c, ans=0;
	n=getnum(); m=getnum();
	int i, j, t;
	for1(i, 1, n) for1(j, 1, m) {
		for(c=getchar(); c!='R' && c!='F'; c=getchar());
		if(c=='F') imap[i][j]=1;
	}
	for1(i, 1, n) {
		t=0;
		for1(j, 1, m)
			if(imap[i][j]) l[i][j]=t; 
			else L[i][j]=0, t=j;
		t=m+1;
		for3(j, m, 1)
			if(imap[i][j]) r[i][j]=t; 
			else R[i][j]=m+1, t=j;
	}
	for1(j, 0, m+1) R[0][j]=m+1;
	for1(i, 1, n) for1(j, 1, m)
		if(imap[i][j]) {
			h[i][j]=h[i-1][j]+1;
			L[i][j]=max(l[i][j]+1, L[i-1][j]);
			R[i][j]=min(r[i][j]-1, R[i-1][j]);
			ans=max((R[i][j]-L[i][j]+1)*h[i][j], ans);
		}
	print(ans*3);
	return 0;
}

