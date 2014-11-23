#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
using namespace std;
#define FOR(i,a,n) for(i=a;i<=n;++i)
#define CC(i) memset(i,0,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

const int maxn=3000, oo=1000000000;
int f[maxn][maxn];
char str1[maxn], str2[maxn];

int main() {
	scanf("%s%s", str1, str2);
	int len1=strlen(str1), len2=strlen(str2), k;
	scanf("%d", &k);
	int i, j;
	FOR(i, 0, len1) f[i][0]=i*k;
	FOR(i, 0, len2) f[0][i]=i*k;
	int min1, min2, min3;
	FOR(i, 1, len1) FOR(j, 1, len2) {
		f[i][j]=min( min(f[i-1][j]+k, f[i][j-1]+k), f[i-1][j-1]+abs((int)str1[i-1]-(int)str2[j-1]) );
	}
	printf("%d\n", f[len1][len2]);
	
	return 0;
}

