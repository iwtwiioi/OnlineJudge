#include <cstdio>
using namespace std;
int n, l, now, s, ans;
bool fx;
int main() {
	scanf("%d%d%d", &n, &l, &now);
	fx = now > l; s = 0;
	for(int i = 2; i < n; ++i) {
		l = now;
		scanf("%d", &now);
		if(now > l == fx) s++;
		else {
			ans += s;
			s = 0;
			fx = now > l;
		}
	}
	printf("%d",n-ans);
	return 0;
}