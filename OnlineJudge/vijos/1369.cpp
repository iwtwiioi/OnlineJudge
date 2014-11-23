#include <cstdio>
using namespace std;
#define FOR(i, a, n) for(i = a; i <= n; ++i)

void setIO() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
}
const int maxn = 300010;
int n, k, now, a[maxn], b[maxn], f[maxn], i, j, num, ans1, ans2;

void readin() {
	scanf("%d%d", &n, &k);
	FOR(i, 1, n) scanf("%d", &a[i]);
	FOR(i, 1, k-1) if(a[i] < a[k]) b[++num] = a[i];
	b[++num] = a[k];
	now = num;
	FOR(i, k+1, n) if(a[i] > a[k]) b[++num] = a[i];
}

int main() {
	setIO();
	readin(); //离散
	
	FOR(i, 1, num) f[i] = 1;
	FOR(i, 1, now-1) FOR(j, 1, i-1) {
		if(b[i] > b[j] && f[i] < f[j] + 1)
			f[i] = f[j] + 1;
		if(f[i] > ans1 && b[i] < b[now])
			ans1 = f[i];
	}
	FOR(i, now+1, num) FOR(j, now+1, i-1) {
		if(b[i] > b[j] && f[i] < f[j] + 1)
			f[i] = f[j] + 1;
		if(f[i] > ans2 && b[i] > b[now])
			ans2 = f[i];
	}
	printf("%d\n", ans1 + ans2 + 1);
	
	return 0;
}

