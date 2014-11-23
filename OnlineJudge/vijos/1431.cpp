#include <cstdio>
using namespace std;
int m, s, t, i, ans1, ans2;

int main() {
	scanf("%d%d%d", &m, &s, &t);
	for(i = 1; i <= t; ++i) {
		ans1 += 17;
		if(m >= 10) ans2 += 60, m -= 10;
		else m += 4;
		if(ans1 < ans2) ans1 = ans2;
		if(ans1 >= s) break;
	}
	if(ans1 >= s) printf("Yes\n%d\n", i);
	else printf("No\n%d\n", ans1);
	
	return 0;
}
