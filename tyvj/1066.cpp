#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
#define FOR(i, a, n) for(i=a;i<=n;++i)

const int maxn = 10005;
int a[maxn], n, ans;
struct cmp { bool operator () (const int& a, const int& b) { return a > b; } };
priority_queue<int, vector<int>, cmp > q;
int main() {
	scanf("%d", &n);
	int i, t1, t2;
	FOR(i, 1, n) { scanf("%d", &a[i]); q.push(a[i]); }
	FOR(i, 1, n-1) {
		t1 = q.top(); q.pop(); t2 = q.top(); q.pop();
		ans += t1+t2; q.push(t1+t2);
	}
	printf("%d\n", ans);
	return 0;
}
