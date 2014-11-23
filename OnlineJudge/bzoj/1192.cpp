#include <cstdio>
using namespace std;

int ans, n;

int main() {
	scanf("%d", &n);
	int m=1;
	while(n>0) {
		ans++;
		n-=m;
		m<<=1;
	}
	printf("%d\n", ans);
	return 0;
}
