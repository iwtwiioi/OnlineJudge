#include <cstdio>
#include <set>
using namespace std;
set<int> s;
int main() {
	int t, n, r, i; scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		s.clear();
		scanf("%d", &r); printf("%d", r); s.insert(r);
		for(i=2; i<=n; ++i) {
			scanf("%d", &r);
			if(s.count(r)==0) printf(" %d", r), s.insert(r);
		}
		puts("");
	}
	return 0;
}