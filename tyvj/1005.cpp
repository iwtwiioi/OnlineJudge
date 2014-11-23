//d[i] = max{d[i], d[i-v]+w}
#include <cstdio>
using namespace std;
int max(const int& a, const int& b) { return a > b ? a : b; }
int T, M, d[1005], v, w, i, ans;
int main() {
	scanf("%d%d", &T, &M);
	while(M--) {
		scanf("%d%d", &v, &w);
		for(i = T; i-v >= 0; --i) { d[i] = max(d[i], d[i-v]+w); ans = max(ans, d[i]); }
	}
	printf("%d\n", ans);
	return 0;
}
