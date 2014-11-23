#include <cstdio>
#include <iostream>
using namespace std;
#define FOR(i, a, n) for(i = a; i <= n; ++i)

const int maxn = 3050;
int i, j, num, f[maxn], seq1[maxn], seq2[maxn], n;

int max(const int& a, const int& b) { return a < b ? b : a; }

int main() {
	scanf("%d%d", &n);
	FOR(i, 1, n) scanf("%d", &seq1[i]);
	FOR(i, 1, n) scanf("%d", &seq2[i]);
	FOR(i, 1, n) FOR(j, 1, n)
		if(seq1[i] == seq2[j]) f[j] = f[j-1] + 1;
		else f[j] = max(f[j], f[j-1]);
	cout << f[n] << endl;
	return 0;
}