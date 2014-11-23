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
int imap[N][N], sum[N][N][2], f[N][N][2];

int main() {
	int n, m, c, ans=0;
	n=getnum(); m=getnum();
	int i, j, l, r;
	for1(i, 1, n) for1(j, 1, m) {
		for(c=getchar(); c!='R' && c!='F'; c=getchar());
		imap[i][j]=c=='R'?-1:1;
		if(c=='F') {
			sum[i][j][0]=sum[i][j][1]=1;
			sum[i][j][0]+=sum[i][j-1][0];
			sum[i][j][1]+=sum[i-1][j][1];
		}
	}
	for1(i, 1, n) for1(j, 1, m) {
		if(sum[i][j][0]) {
			f[i][j][0]=sum[i][j][0]>=sum[i][j][1]?sum[i][j][0]:1,
			f[i][j][1]=sum[i][j][1]>sum[i][j][0]?sum[i][j][1]:1;
			l=min(sum[i][j][0]-1, f[i-1][j-1][0])+1;
			r=min(sum[i][j][1]-1, f[i-1][j-1][1])+1;
			if(i==n && j==m) { 
				printf("f[n][m][0]:%d  f[n][m][1]:%d  l:%d  r:%d\n",
				f[n][m][0], f[n][m][1], l, r);
			}
			if(l>0 && r>0 && l*r>f[i][j][0]*f[i][j][1])
				f[i][j][0]=l, f[i][j][1]=r;
			if(i==n && j==m) { 
				printf("f[n][m][0]:%d  f[n][m][1]:%d  l:%d  r:%d\n",
				f[n][m][0], f[n][m][1], l, r);
			}
			ans=max(f[i][j][0]*f[i][j][1], ans);
		}		
	}
	for1(i, 1, n) {
		for1(j, 1, m) printf("%d ", sum[i][j][0]);
		printf("\n");
	}
	printf("\n");
	for1(i, 1, n) {
		for1(j, 1, m) printf("%d ", sum[i][j][1]);
		printf("\n");
	}
	printf("\n");
	for1(i, 1, n) {
		for1(j, 1, m) printf("%d ", f[i][j][0]);
		printf("\n");
	}
	printf("\n");
	for1(i, 1, n) {
		for1(j, 1, m) printf("%d ", f[i][j][1]);
		printf("\n");
	}
	printf("\n");
	print(ans*3);
	return 0;
}

