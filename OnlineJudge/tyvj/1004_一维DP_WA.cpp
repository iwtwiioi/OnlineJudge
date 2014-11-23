#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define FOR(i, a, n) for(i=a;i<n;++i)
const int maxn = 105;
int d[maxn*maxn], r, c, ans;
struct im {
	int h, x, y;
	bool operator < (const im& b) const { return h < b.h; }
}imap[maxn*maxn];

int max(const int& a, const int& b) { return a > b ? a : b; }
bool check(const im& a, const im& b) {
	if(a.x == b.x) return (abs(a.y-b.y) == 1);
	if(a.y == b.y) return (abs(a.x-b.x) == 1);
	return false;
}

int main() {
	scanf("%d%d", &r, &c);
	int i, j, k = 0;
	FOR(i, 0, r) FOR(j, 0, c) { scanf("%d", &imap[k].h); imap[k].x = i; imap[k++].y = j;}
	sort(imap, imap+r*c);
	FOR(i, 0, k) FOR(j, 0, i) {
		if(check(imap[i], imap[j]) && d[i] < d[j]+1) d[i] = d[j]+1;
		ans = max(ans, d[i]);
	}
	printf("%d\n", ans+1);
	return 0;
}
