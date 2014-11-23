#include <cstdio>
using namespace std;
#define FOR(i, a, n) for(i = a; i <= n; ++i)

const int MAXN = 80;
int num[MAXN], n, i, j, k;

int main() {
	scanf("%d", &n);
	num[1] = num[0] = 1;
	FOR(i, 1, n+1) { 
		k = 0;
		FOR(j, 1, num[0]) { num[j] = num[j] << 1 | k; k = num[j] / 10; num[j] %= 10; }
		if(k) num[++num[0]]++;
	}
	num[1] -= 2; i = 1;
	while(num[i] < 0) {
		num[i] += 10;
		num[++i] -= 1;
	}
	while(!num[num[0]]) num[0]--;
	for(i = num[0]; i > 0; --i) printf("%d", num[i]);
	return 0;
}
