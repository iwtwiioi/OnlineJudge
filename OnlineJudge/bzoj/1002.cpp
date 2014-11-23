#include <cstdio>
#include <cstring>
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
#define print(a) printf("%d", a);

struct bignum {
	int d[10000];
}f[105];

bignum mul(bignum a, const int &k) {
	for(int i=1; i<=a.d[0]; ++i) a.d[i]*=k;
	for(int i=1; i<=a.d[0]; ++i)
		a.d[i+1]+=a.d[i]/10, a.d[i]%=10;
	if(a.d[a.d[0]+1]) ++a.d[0];
	return a;
}
bignum minus(bignum a, const bignum &b) {
	a.d[1]+=2; int j=1;
	while(a.d[j]>=10) a.d[j]%=10, a.d[++j]++;
	for(int i=1; i<=a.d[0]; ++i) {
		a.d[i]-=b.d[i];
		while(a.d[i]<0) a.d[i]+=10, --a.d[i+1];
	}
	while(!a.d[a.d[0]]) --a.d[0];
	return a;
}
bignum plus(bignum a, const int &k) {
	a.d[1]+=k; int i=1;
	while(a.d[i]>=10) a.d[i+1]+=a.d[i]/10, a.d[i]%=10;
	if(a.d[a.d[0]+1]) ++a.d[0];
	return a;
}

int main() {
	int n;
	read(n);
	f[1].d[1]=1; f[2].d[1]=5;
	f[1].d[0]=f[2].d[0]=1;
	int i;
	for1(i, 3, n) 
		f[i]=minus(mul(f[i-1], 3), f[i-2]);
	for3(i, f[n].d[0], 1) printf("%d", f[n].d[i]);
	return 0;
}

