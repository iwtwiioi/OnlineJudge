#include <cstdio>
using namespace std;
int max(const int& a, const int& b) { return a > b ? a : b; }
int T, M, d[1005], v, w, i, ans;
int main() {
	scanf("%d%d", &M, &T);
	while(M--) {
		scanf("%d%d", &w, &v);
		for(i = T; i-v >= 0; --i) d[i] = max(d[i], d[i-v]+w);
	}
	printf("%d\n", d[T]);
	return 0;
}
