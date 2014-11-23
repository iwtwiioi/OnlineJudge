#include <cstdio>
using namespace std;
int n, l, now, ans;
bool fx;
int main() {
	scanf("%d%d", &n, &l);
	for(int i = 1; i < n; ++i) {
		scanf("%d", &now);
		if(now > l && fx) { ans++; fx = 0; }
		else if(now < l && !fx) { ans++; fx = 1;}
	}
	printf("%d",ans+2);
	return 0;
}