#include <cstdio>
using namespace std;
int max(const int& a, const int& b) { return a > b ? a : b; }
int T, M, d[45005], v, w, i, ans;
int main() {
	scanf("%d%d", &T, &M);
	while(M--) {
		scanf("%d", &v);
		for(i = T; i-v >= 0; --i) d[i] = max(d[i], d[i-v]+v);
	}
	printf("%d\n", d[T]);
	return 0;
}
