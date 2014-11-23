#include <cstdio>
using namespace std;
#define lowbit(x) x&-x

const int maxn = 100000;
int c[maxn], n, q, t, a, b, k;

int sum(int x) { int r = 0; while(x > 0) r += c[x], x -= lowbit(x); return r; }
void add(int x, int k) { while(x <= n) c[x] += k, x += lowbit(x); }

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) { scanf("%d", &a); add(i, a); }
	scanf("%d", &q);
	while(q--) {
		scanf("%d%d", &t, &a);
		if(t == 1) {
			scanf("%d%d", &b, &k);
			for(int j = a; j <= b; ++j) add(j, k);
		}
		else printf("%d", sum(a) - sum(a-1));
	}
	return 0;
}