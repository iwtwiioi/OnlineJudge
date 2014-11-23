#include <cstdio>
using namespace std;

int main() {
	int n, a = 0, b, ans = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) { scanf("%d", &b); if(b > a) ans += b-a; a = b; }
	printf("%d", ans);
	return 0;
}