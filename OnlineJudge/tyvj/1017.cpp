#include <cstdio>
using namespace std;
#define FOR(i,a,n) for(i=a;i<=n;++i)
void swap(int& a, int& b) { int t = a; a = b; b = t; }

int p[1005], n, m, ans;
int find(int x) { if(p[x] == x) return x; return p[x] = find(p[x]);  }

int main() {
	scanf("%d%d", &n, &m);
	int i, a, b;
	FOR(i, 1, m) p[i] = i;
	FOR(i, 1, m) {
		scanf("%d%d", &a, &b);
		if(a > b) swap(a, b);
		if(find(a) != find(b))
			p[find(b)] = find(a);
		else ans++;
	}
	printf("%d\n", ans);
	return 0;
}
