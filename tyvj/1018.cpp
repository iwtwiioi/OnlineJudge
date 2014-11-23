#include <cstdio>
using namespace std;

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
	int n, k;
	scanf("%d%d", &n, &k);
	num[0] = num[1] = 1;
	for(int i = 2; i <= n; ++i) multi(i);
	int pos = 1, pos2;
	while(!num[pos]) pos++;
	pos2 = pos+k-1;
	if(pos2 > num[0]) pos2 = num[0];
	for(int i = pos2; i >= pos; --i) printf("%d", num[i]);
	printf("\n");
	return 0;
}
