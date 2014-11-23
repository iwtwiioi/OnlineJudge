#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

#define FOR(i, a, n) for(i = a; i <= n; ++i)

void setIO() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
}

const int maxn = 2010;

string s[maxn];
int n, i, j, f[maxn], ans;

int max(const int& a, const int& b) { return a > b ? a : b; }
int min(const int& a, const int& b) { return a < b ? a : b; }

int l, _i;
bool check(int a, int b) {
	l = min(s[a].size(), s[b].size());
	FOR(_i, 0, l-1) if(s[a][_i] != s[b][_i]) return false;
	return true;
}

int main() {
	setIO();
	
	cin >> n;
	FOR(i, 1, n) cin >> s[i];
	FOR(i, 1, n) {
		f[i] = 1;
		FOR(j, 1, i-1)
			if(check(i, j) && f[i] < f[j] + 1)
				f[i] = f[j] + 1, ans = max(ans, f[i]);
	}
	cout << ans << endl;
	return 0;
}

