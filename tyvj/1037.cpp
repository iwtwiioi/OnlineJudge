#include <cstdio>
using namespace std;
#define FOR(i, a, n) for(i=a;i<=n;++i)

const int maxn = 100;
int num[maxn];

void multi(int a) {
	int i;
	for(i = 1; i <= num[0]; ++i) num[i] *= a;
	for(i = 1; i <= num[0] || num[i] > 10; ++i) if(num[i] >= 10) {
		num[i+1] += (num[i]/10);
		num[i] %= 10;
	}
	while(!num[i]) --i;
	num[0] = i;
}

int main() {
	int n, k, t, i, j;
	int pos=1, pos2;
	scanf("%d%d", &n, &k);
	num[0]=num[1]=1;
	FOR(i, 2, n) { 
		multi(i);
		//for(j=num[0]; j>0; --j) printf("%d", num[j]);
		//printf(" ");
		pos=1;
		while(!num[pos]) pos++;
		FOR(pos2, 1, 20-pos+1) num[pos2]=num[pos+pos2-1];
		t=pos2-1;
		for(; pos2<=num[0]; ++pos2) num[pos2]=0;
		num[0]=t;
		//for(j=num[0]; j>0; --j) printf("%d", num[j]);
		//printf("\n");
	}
	pos2=k;
	if(pos2>num[0]) pos2=num[0];
	for(i=pos2; i>0; --i) printf("%d", num[i]);
	printf("\n");
	return 0;
}
