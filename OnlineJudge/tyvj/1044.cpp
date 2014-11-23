#include <iostream>
using namespace std;
int d[30][30], n, t, i, j;
#define FOR(i, a, n) for(i=a;i<=n;++i)
int max(const int& a, const int& b) { return a > b ? a : b; }
int main() {
	cin >> n;
	FOR(i, 1, n) FOR(j, 1, i) cin >> d[i][j];
	for(i = n-1; i > 0; --i) FOR(j, 1, i) d[i][j] += max(d[i+1][j], d[i+1][j+1]);
	cout << d[1][1] << endl;
	return 0;
}
