#include <cstdio>
using namespace std;

const int N=1005;
int a[N];

int mpow(int a, int b) {
	int ret=1;
	while(b) {
		if(b&1) ret*=a;
		a*=a;
		b>>=1;
	}
	return ret;
}

int main() {
	int n, m, t, k=0, i, j;
	scanf("%d%d", &n, &m);
	for(i=0; i<=100; ++i) {
		a[++k]=mpow(n, i); t=k;
		for(j=1; j<t; ++j) {
			a[++k]=a[j]+a[t];
			if(k==m) { printf("%d\n", a[k]); return 0; }
		}
	}
	return 0;
}
