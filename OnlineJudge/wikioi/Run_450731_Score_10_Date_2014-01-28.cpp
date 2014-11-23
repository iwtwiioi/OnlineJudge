#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 10e5+10;
int sum[maxn], cl[maxn], t[maxn], d[maxn], s[maxn], n, m, last;

int check(int r) {
	if(last < r) {
		for(int i = last; i <= r; ++i) {
			sum[s[i]] += d[i]; sum[t[i]] -= d[i];
		}
		last = r;
	}
	int ret = 0;
	for(int i = 1; i <= n; ++i) {
		ret += sum[i];
		if(ret > cl[i]) return 0;
	}
	return 1;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", &cl[i]);
	for(int i = 1; i <= m; ++i) scanf("%d%d%d", &d[i], &s[i], &t[i]);
	int l = 1, r = m, mid;
	while(l <= r) {
		mid = (l + r) >> 1;
		if(check(mid)) l = mid+1;
		else r = mid-1;
	}
	if(l == m-1) printf("0");
	else printf("-1\n%d", l);
	
	return 0;
}