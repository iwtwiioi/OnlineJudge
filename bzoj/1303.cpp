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

const int N=100005;
int w[N], l[N<<1], r[N<<1], sum[N], pos;

int main() {
	int i, n, b, ans=0;
	read(n); read(b);
	for1(i, 1, n) {
		read(w[i]);
		if(w[i]==b) pos=i, w[i]=0;
		else w[i]=w[i]<b?-1:1;
	}
	l[n]=r[n]=1;
	for3(i, pos-1, 1) sum[i]=sum[i+1]+w[i], l[n+sum[i]]++;
	for1(i, pos+1, n) sum[i]=sum[i-1]+w[i], r[n+sum[i]]++;
	for1(i, 0, n<<1) ans+=l[i]*r[(n<<1)-i];
	print(ans);
	return 0;
}

