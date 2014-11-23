#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define FOR(i,a,n) for(i=a;i<=n;++i)
#define CC(i,a) memset(i,a,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rdin(a) scanf("%d", &a)
#define prin(a) printf("%d", a);

const int N=1000005;

int main() {
	int n;
	rdin(n);
	int i;
	double t;
	double money=1, gu=0, _m, _g;
	FOR(i, 1, n) {
		scanf("%lf", &t);
		_m=money; _g=gu;
		money=max(_m, _g*t);
		gu=max(_g, _m/t);
	}
	money=max(money, gu*t);
	prin((int)(money+0.5));
	return 0;
}

