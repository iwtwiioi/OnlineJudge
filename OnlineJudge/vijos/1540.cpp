#include <cstdio>
#include <cmath>
using namespace std;

#define FOR(i, a, n) for(int i = a; i < n; ++i)

const int maxn = 30000;
int p[maxn], s[maxn], tag[maxn], n, t;

int set(int a) { if(a != p[a]) { int t = set(p[a]); tag[a] += tag[p[a]]; p[a] = t; } return p[a]; }

int main() {
	scanf("%d", &t);
	FOR(i, 1, maxn+1) p[i] = i, s[i] = 1;
	char ch;
	int a, b, p1, p2;
	FOR(i, 1, t+1) {
		scanf("%s%d%d", &ch, &a, &b);
		p1 = set(a);
		p2 = set(b);
		if(ch == 'M') {
			p[p1] = p2;
			tag[p1] += s[p2];
			s[p2] += s[p1];
		}
		else if(p1 != p2) printf("-1\n");
		else printf("%d\n", int(abs(tag[b] - tag[a])-1) );
	}
	
	return 0;
}
