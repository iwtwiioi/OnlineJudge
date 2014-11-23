#include <cstdio>
using namespace std;
int max(const int& a, const int& b) {return a > b ? a : b;}
int f[1005], w, v;
int main() {
	int V, n, i, j;
	scanf("%d%d", &V, &n);
	for(i = 0; i < n; ++i) {
		scanf("%d%d", &v, &w);
		for(j = V; j >= v; --j)
			f[j] = max(f[j], f[j-v]+w);
	}
	printf("%d", f[V]);
	return 0;
}
