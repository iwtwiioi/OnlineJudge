#include <cstdio>
using namespace std;
int n, l, now, ans = -1;
int s;
int main() {
	scanf("%d%d", &n, &l);
	for(int i = 1; i < n; ++i) {
		scanf("%d", &now);
		if(now > l && s != -1) { ans++; s = -1; }
		else if(now < l && s != 1) { ans++; s = 1; }
        l = now;
	}
	printf("%d", ans+2);
	return 0;
}
	