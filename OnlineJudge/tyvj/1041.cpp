#include <cstdio>
#include <cstring>
using namespace std;
#define FOR(i,a,n) for(i=a;i<=n;++i)
#define CC(i) memset(i,0,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

const int maxn=300;
int num[maxn], ans[maxn];

void plus(int* a, int* b) {
	int s=max(a[0], b[0]), i;
	FOR(i, 1, s) {
		a[i]+=b[i];
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	if(a[s+1]) a[0]=s+1;
	else a[0]=s;
}

void minus(int* a, int* b) {
	int i;
	FOR(i, 1, a[0]) {
		a[i]-=b[i];
		if(a[i]<0) {
			a[i]+=10;
			--a[i+1];
		}
	}
	while(!a[a[0]]) --a[0];
}

void print(int* a) {
	for(int i=a[0]; i; --i) printf("%d", a[i]);
	printf("\n");
}

int main() {
	int s=1; char c;
	int i;
	ans[0]=1;
	while(~scanf("%c", &c)) {
		if(c=='-') { if(s==-1) minus(ans, num); else plus(ans, num); s=-1; CC(num); }
		if(c=='+') { if(s==-1) minus(ans, num); else plus(ans, num); s=1;  CC(num); }
		if('0'<=c && c<='9') {
			for(i=num[0]; i; --i) num[i+1]=num[i];
			num[1]=(c-'0'); ++num[0];
		}
	}
	if(s==-1) minus(ans, num); else plus(ans, num); s=-1;
	print(ans);
	return 0;
}

